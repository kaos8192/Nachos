/*
 *  Copyright 2012-2016 Robert Marmorstein
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "filesys.h"
#include "handle.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// vector of file handles for 
vector<FileHandle*> open_file_list;
// global file descriptor
int descriptor = 0;

/*
 * "Zero" out the m_disk with handy-dandy little '*'s
 */
void Filesystem::format()
{
    //(m_disk_size/1048)*24
    //Easier for individual tasks if we use DirEntry->size or something
    unsigned int biggness = (m_disk_size/1048)*24;

    //Fill the m_disk with '*' (sentinel char)
    for(unsigned int i = 0; i < biggness; ++i)
    {
        m_disk[i] = '*';
    }
}


/*
 * Creates a file if has space in dir, space on disk, and name is valid.
 * Returns true on create.
 * Returns false if create fails for some reason.
 */
bool Filesystem::create(const string name)
{
    //Set the sizes for looping and tracking dir positions
    unsigned int bigg = m_disk_size/1048;
    unsigned int maxsize = bigg*24;

    //Loop through and check if filename is already in m_dir
    for(unsigned int m = 0; m < bigg; ++m){
        if(strncmp(m_dir[m].filename,name.c_str(),16) == 0){
            return false;
        }
    }

    //Loop through if filename is fresh
    for(unsigned int i = 0; i < bigg; ++i){
        //Check if there are sentinels in the location
        if(m_dir[i].filename[0]=='*'){
            //Loop through and find the maxsize area
            for(unsigned int j = 0; j < bigg; ++j){
                //If there is a file in a "valid" location, increase maxsize
                if(maxsize < m_dir[j].pos && m_dir[j].filename[0] !='*'){
                    maxsize = m_dir[j].pos + 1024;
                }
            }
            //Create the file
            strncpy(m_dir[i].filename, name.c_str(),16);
            m_dir[i].size = 0;
            m_dir[i].pos = maxsize; //Maybe Map it 1-to-1,
            //but it can cause issues for sub-dir,
            //otherwise loop through directory, looking for last block,
            //and then take the next one.	
            //Successful creation
            return true;
        }
    }
    //Failed create for non-duplicate reasons
    return false;
}

/*
 *  Basically "ls" w/ size in the CLI.
 *  Returns a formatted string of created files and sizes.
 *  Should not print out the position, since user doesn't need to know.
 *  Each dir has a line.
 *  Filename left-just, columns of 16-char wide (space padded).
 *  Size on same line, left-just, 8-char wide (space padded).
 *  No commas or units, just raw num of bytes.
 *  Should not include deleted or not created files.
 *  SHOULD use m_dir and loop through.
 */
string Filesystem::list() const
{
    //Set the sizes for looping and MAYBE pos tracking
    unsigned int dir_size = m_disk_size/1048;
    //unsigned int max_size = dir_size*24;

    //ostringstream for format
    ostringstream oss;
    //Return string
    string ret_str = "";

    //Loop the directory
    for(unsigned int i = 0; i < dir_size; ++i)
    {
        //Verify that the current position is not "zeroed"
        if(m_dir[i].filename[0] != '*')
        {
            //Format the output and store
            oss << left << setw(16) << m_dir[i].filename
                << left << setw(8) << m_dir[i].size << "\n";
        }
    }
    //Send the formated output to a string and return
    ret_str = oss.str();
    return ret_str;
}

/*
 * "Removes" a file by "zeroing" the filename with sentinels.
 * Returns false if file isn't present, else remove and return true.
 */
bool Filesystem::rm(const string name)
{
    //Get the directory size
    unsigned int dir_size = m_disk_size/1048;

    //Loop the directory
    for(unsigned int i = 0; i < dir_size; ++i)
    {
        //Check the file
        if(strncmp(m_dir[i].filename,name.c_str(),16) == 0)
        {
            //"Zero" out the filename
            for(int j = 0; j < 16; ++j)
            {
                m_dir[i].filename[j] = '*';
            }
            //Successful rm
            return true;
        }
    }

    //File not found
    return false;
}

bool Filesystem::rename(const string old_name, const string new_name) 
{

    // get size of directory
    unsigned int dir_size = m_disk_size/1048;

    // loop through directory
    for(unsigned int i = 0; i < dir_size; ++i)
    {
        // if the old_name is the filename,
        if(strncmp(m_dir[i].filename,old_name.c_str(),16) == 0)
        {
            // copy new_name into filename
            strncpy(m_dir[i].filename, new_name.c_str(),16);
            return true;
        }
    }

    return false;
}

bool Filesystem::copy(const string old_name, const string new_name)
{
    unsigned int bigg = m_disk_size/1048;
    unsigned int maxsize = bigg*24;
    unsigned int old = 0;

    //Loop through and check if filename is actually in m_dir
    for(unsigned int m = 0; m < bigg; ++m){
        if(strncmp(m_dir[m].filename,old_name.c_str(),16) == 0){
            old = m;	

            for(unsigned int i = 0; i < bigg; ++i){
                //Check if there are sentinels in the location
                if(m_dir[i].filename[0]=='*'){
                    //Loop through and find the maxsize area
                    for(unsigned int j = 0; j < bigg; ++j){
                        //If there is a file in a "valid" location, increase maxsize
                        if(maxsize < m_dir[j].pos && m_dir[j].filename[0] !='*'){
                            maxsize = m_dir[j].pos + 1024;
                        }
                    } 
                    //Copy the file
                    strncpy(m_dir[i].filename, new_name.c_str(),16);
                    m_dir[i].size = m_dir[m].size;
                    m_dir[i].pos = maxsize; 
                    //Successful copy
                    return true;
                } // if statment for copying the file
            } // for loop for creating the copy file
        } // if loop checking to see if the file we are copying does exist. 

    } // for loop for searching for the file we want to copy
    return false; // Failed to copy because the file does not exist or we cannot create a new file to copy into 
}

int Filesystem::open(const string name)
{
    // make new FileHandle
    FileHandle* handle = new FileHandle();

    // loop through m_disk and find the file called name
    unsigned int dir_size = m_disk_size/1048;

    for(unsigned int i = 0; i < dir_size; ++i)
    {
        // if the name is the filename,
        if(strncmp(m_dir[i].filename,name.c_str(),16) == 0)
        {
            // set our newly made handle's pos, size, offset, and row
            handle->pos = m_dir[i].pos;
            handle->size = m_dir[i].size;
            handle->offset = 0;

            // push into vector
            open_file_list.push_back(handle);

            // return position of handle as the fd
            return (open_file_list.size() - 1); 
        }
    }

    // could not find the file
    return -1;

}


bool Filesystem::close(const int fd) const
{
    // check if the fd is valid AND if the FileHandle exists
    if (fd < open_file_list.size() and open_file_list[fd] != 0){
        // delete the data and return true
        delete open_file_list[fd];
        open_file_list[fd] = NULL;
        return true;
    }
    // if fd is invalid or we already deleted that fd, return false
    return false;

}


bool Filesystem::read(const int fd, string &buffer, const unsigned int size) const
{
    //Get the file handle
    FileHandle* handle = open_file_list[fd];
    //Add position and offset and size
    const int pos = handle->pos;
    const int offset = handle->offset;
    const int hsize = handle->size;
    const int poffset = pos + offset;
    //Calculate dir size for looping
    unsigned int dir_size = m_disk_size/1048;

    //Verify size constraint of file and requested
    if(offset + size <= hsize and poffset+size <= m_disk_size)
    {
        //Loop the file area to read
        for(unsigned int j = 0; j < size; ++j)
        {
            //Append char to buffer
            buffer += m_disk[pos+j];
        }
        //Successful read
        return true;
    }
    //Exceeds file or disk
    return false;
}


bool Filesystem::write(const int fd, const string str, const unsigned int size)
{
    //Get the file handle
    FileHandle* handle = open_file_list[fd];
    //Add position and offset
    int pos = handle->pos;
    int offset = handle->offset;
    //Size for adjustment
    int hsize = handle->size;
    //hsize += size;
    //Calculate dir size for looping
    unsigned int dir_size = m_disk_size/1048;

    //cerr << pos << endl;
    //Verify size constraint with disk
    if(((pos+offset)+size) <= m_disk_size)
    {
        //Loop directory
        for(unsigned int i = 0; i < dir_size; ++i)
        {
            //Check if in the correct position
            if(m_dir[i].pos == pos)
            {
                //Loop the file area to write
                for(unsigned int j = 0; j < size; ++j)
                {
                    ++hsize;
                    m_disk[((pos+offset))] = str[j];
                    ++offset;
                    if((pos+offset) > m_disk_size)
                    {
                        return false;
                    }
                }
                //Successful write
                //Fix sizes
                handle->size = hsize;
                m_dir[i].size = hsize;
                //Fix offset
                handle->offset = offset;
                //Return success
                return true;
            }
        }
    }
    //Disk overflow and return false
    return false;
}
