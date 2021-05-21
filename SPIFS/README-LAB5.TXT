OMIS (our Other Mask is Input Sanitation) Documentation
Lab 5 -- SPIFS

Group Members:
    Chad Wilson
    Joshua Obernesser
    Geir Anderson

Member work:
Chad Wilson:
    Implemented rename
    Implemented open
    Implemented close

    Individual -- Subdirectories
    Added 'isDir' boolean to DirEntry struct to flag files as 
        directories. This breaks things by adding a bunch of extra data to the
        entry and I don't know how to fix it.
    Added an in statement in create the check if the file ends in
        a /, if it does isDir is set to true, else false.
        This itself probably works, but because of all the extra data stuff... vvv
    I tried to make a test file, it wouldnt work and I couldn't get it to compile.
        Ontop of several issues with compiling it wouldn't have worked anyways
        because I was not handling the extra data :( 

    C'est la vie!     ---     ¯\_(ツ)_/¯

Joshua Obernesser:
	Implimented Create
	Implimented Copy
	Almost completely implimented permissions, breaks down in read for some reason. 
	Implimented Test for permissions

Geir Anderson:
    filesys.h:
        Created DirEntry struct.
    operations.cpp:
        Implemented Format.
        Implemented List.
        Implemented rm.
        Implemented Read.
        Implemented Write.
        Fixed Open/Close
        Started implementing Defragmentation.
    tests/:
        Started adding test files for defrag and added tests to makefile and base_test.h
    misc.:
        Fixed typos and commented descriptions.
