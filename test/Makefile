# use normal make for this Makefile
#
# Makefile for building user programs to run on top of Nachos
#
# Several things to be aware of:
#
#    Nachos assumes that the location of the program startup routine (the
# 	location the kernel jumps to when the program initially starts up)
#       is at location 0.  This means: start.o must be the first .o passed 
# 	to ld, in order for the routine "Start" to be loaded at location 0
#

# if you are cross-compiling, you need to point to the right executables
# and change the flags to ld and the build procedure for as

GCCDIR = /usr/local/mips-nachos/

LDFLAGS = -T script -N
ASFLAGS = -mips2
CPPFLAGS = $(INCDIR)

# if you aren't cross-compiling:
# GCCDIR =
# LDFLAGS = -N -T 0
# ASFLAGS =
# CPPFLAGS = -P $(INCDIR)

PATH = $(GCCDIR):/lib:/usr/bin:/bin

CC = $(GCCDIR)mips-gcc -B/usr/local/mips-nachos/
AS = $(GCCDIR)mips-as
LD = $(GCCDIR)mips-ld

CPP = mips-gcc -E
INCDIR =-I../userprog -I../threads
CFLAGS = -G 0 -c $(INCDIR)

all: halt shell matmult sort create open read exec exit join ej_child ej_parent console cat cp argtest argtest_child

start.o: start.s ../userprog/syscall.h
	$(CPP) $(CPPFLAGS) start.c > strt.s
	$(AS) $(ASFLAGS) -o start.o strt.s
	rm strt.s

halt.o: halt.c
	$(CC) $(CFLAGS) -c halt.c
halt: halt.o start.o
	$(LD) $(LDFLAGS) start.o halt.o -o halt.coff
	../bin/coff2noff halt.coff halt

shell.o: shell.c
	$(CC) $(CFLAGS) -c shell.c
shell: shell.o start.o
	$(LD) $(LDFLAGS) start.o shell.o -o shell.coff
	../bin/coff2noff shell.coff shell

sort.o: sort.c
	$(CC) $(CFLAGS) -c sort.c
sort: sort.o start.o
	$(LD) $(LDFLAGS) start.o sort.o -o sort.coff
	../bin/coff2noff sort.coff sort

matmult.o: matmult.c
	$(CC) $(CFLAGS) -c matmult.c
matmult: matmult.o start.o
	$(LD) $(LDFLAGS) start.o matmult.o -o matmult.coff
	../bin/coff2noff matmult.coff matmult

create.o: create.c
	$(CC) $(CFLAGS) -c create.c
create: create.o start.o
	$(LD) $(LDFLAGS) start.o create.o -o create.coff
	../bin/coff2noff create.coff create

open.o: open.c
	$(CC) $(CFLAGS) -c open.c
open: open.o open.o
	$(LD) $(LDFLAGS) start.o open.o -o open.coff
	../bin/coff2noff open.coff open

read.o: read.c
	$(CC) $(CFLAGS) -c read.c
read: read.o read.o
	$(LD) $(LDFLAGS) start.o read.o -o read.coff
	../bin/coff2noff read.coff read

exec.o: exec.c
	$(CC) $(CFLAGS) -c exec.c
exec: exec.o exec.o
	$(LD) $(LDFLAGS) start.o exec.o -o exec.coff
	../bin/coff2noff exec.coff exec

exit.o: exit.c
	$(CC) $(CFLAGS) -c exit.c
exit: exit.o exit.o
	$(LD) $(LDFLAGS) start.o exit.o -o exit.coff
	../bin/coff2noff exit.coff exit

join.o: join.c
	$(CC) $(CFLAGS) -c join.c
join: join.o join.o
	$(LD) $(LDFLAGS) start.o join.o -o join.coff
	../bin/coff2noff join.coff join
	
ej_parent.o: ej_parent.c
	$(CC) $(CFLAGS) -c ej_parent.c
ej_parent: ej_parent.o ej_parent.o
	$(LD) $(LDFLAGS) start.o ej_parent.o -o ej_parent.coff
	../bin/coff2noff ej_parent.coff ej_parent

ej_child.o: ej_child.c
	$(CC) $(CFLAGS) -c ej_child.c
ej_child: ej_child.o ej_child.o
	$(LD) $(LDFLAGS) start.o ej_child.o -o ej_child.coff
	../bin/coff2noff ej_child.coff ej_child

console.o: console.c
	$(CC) $(CFLAGS) -c console.c
console: console.o start.o
	$(LD) $(LDFLAGS) start.o console.o -o console.coff
	../bin/coff2noff console.coff console

cat.o: cat.c
	$(CC) $(CFLAGS) -c cat.c
cat: cat.o start.o
	$(LD) $(LDFLAGS) start.o cat.o -o cat.coff
	../bin/coff2noff cat.coff cat

cp.o: cp.c
	$(CC) $(CFLAGS) -c cp.c
cp: cp.o start.o
	$(LD) $(LDFLAGS) start.o cp.o -o cp.coff
	../bin/coff2noff cp.coff cp

argtest.o: argtest.c
	$(CC) $(CFLAGS) -c argtest.c
argtest: argtest.o argtest.o
	$(LD) $(LDFLAGS) start.o argtest.o -o argtest.coff
	../bin/coff2noff argtest.coff argtest

argtest_child.o: argtest_child.c
	$(CC) $(CFLAGS) -c argtest_child.c
argtest_child: argtest_child.o argtest_child.o
	$(LD) $(LDFLAGS) start.o argtest_child.o -o argtest_child.coff
	../bin/coff2noff argtest_child.coff argtest_child
