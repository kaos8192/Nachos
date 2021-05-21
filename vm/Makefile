# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the virtual memory assignment
#    Defines set up assuming the virtual memory assignment is done before 
# 	the file system assignment. If not, use the "filesys first"  
#	defines below. 
#
# Also, if you want to simplify the translation so it assumes
# only linear page tables, don't define USE_TLB.
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM  -DFILESYS_NEEDED -DFILESYS_STUB -DVM -DUSE_TLB
INCPATH = -I../filesys -I../bin -I../vm -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O)

# if file sys done first!
# DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS -DVM -DUSE_TLB
# INCPATH = -I../vm -I../bin -I../filesys -I../userprog -I../threads -I../machine
# HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H) $(VM_H)
# CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C) $(VM_C)
# C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O) $(VM_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/tired.h ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
list.o: ../threads/list.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h
scheduler.o: ../threads/scheduler.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/scheduler.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/system.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/tired.h ../threads/alarm.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
synch.o: ../threads/synch.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synch.h ../threads/thread.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/list.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/tired.h \
 ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
synchlist.o: ../threads/synchlist.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synchlist.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/synch.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h
system.o: ../threads/system.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/tired.h \
 ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc ../threads/../userprog/bitmap.h \
 ../threads/../userprog/../filesys/openfile.h
thread.o: ../threads/thread.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/thread.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/switch.h ../threads/synch.h \
 ../threads/list.h ../threads/system.h ../threads/scheduler.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/tired.h ../threads/alarm.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
utility.o: ../threads/utility.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/stdarg.h
threadtest.o: ../threads/threadtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/tired.h \
 ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc ../threads/synch.h ../threads/comm.h
interrupt.o: ../machine/interrupt.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/interrupt.h ../threads/list.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../threads/tired.h \
 ../threads/system.h ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
sysdep.o: ../machine/sysdep.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 /usr/include/signal.h /usr/include/bits/signum.h \
 /usr/include/bits/signum-generic.h \
 /usr/include/bits/types/sig_atomic_t.h \
 /usr/include/bits/types/sigset_t.h /usr/include/bits/types/__sigset_t.h \
 /usr/include/bits/types/struct_timespec.h \
 /usr/include/bits/types/siginfo_t.h /usr/include/bits/types/sigval_t.h \
 /usr/include/bits/siginfo-arch.h /usr/include/bits/siginfo-consts.h \
 /usr/include/bits/siginfo-consts-arch.h \
 /usr/include/bits/types/sigevent_t.h /usr/include/bits/sigevent-consts.h \
 /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h \
 /usr/include/bits/types/stack_t.h /usr/include/sys/ucontext.h \
 /usr/include/bits/sigstack.h /usr/include/bits/ss_flags.h \
 /usr/include/bits/types/struct_sigstack.h \
 /usr/include/bits/pthreadtypes.h /usr/include/bits/thread-shared-types.h \
 /usr/include/bits/pthreadtypes-arch.h /usr/include/bits/sigthread.h \
 /usr/include/sys/types.h /usr/include/bits/types/clock_t.h \
 /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h \
 /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h \
 /usr/include/bits/uintn-identity.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/types/struct_timeval.h \
 /usr/include/sys/sysmacros.h /usr/include/bits/sysmacros.h \
 /usr/include/sys/time.h /usr/include/sys/socket.h \
 /usr/include/bits/types/struct_iovec.h /usr/include/bits/socket.h \
 /usr/include/bits/socket_type.h /usr/include/bits/sockaddr.h \
 /usr/include/asm/socket.h /usr/include/asm-generic/socket.h \
 /usr/include/linux/posix_types.h /usr/include/linux/stddef.h \
 /usr/include/asm/posix_types.h /usr/include/asm/posix_types_64.h \
 /usr/include/asm-generic/posix_types.h /usr/include/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h /usr/include/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/bits/types/struct_osockaddr.h /usr/include/sys/file.h \
 /usr/include/fcntl.h /usr/include/bits/fcntl.h \
 /usr/include/bits/fcntl-linux.h /usr/include/linux/falloc.h \
 /usr/include/bits/stat.h /usr/include/sys/un.h /usr/include/sys/mman.h \
 /usr/include/bits/mman.h /usr/include/bits/mman-linux.h \
 /usr/include/unistd.h /usr/include/bits/posix_opt.h \
 /usr/include/bits/environments.h /usr/include/bits/confname.h \
 /usr/include/bits/getopt_posix.h /usr/include/bits/getopt_core.h \
 /usr/include/errno.h /usr/include/bits/errno.h \
 /usr/include/linux/errno.h /usr/include/asm/errno.h \
 /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/system.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../threads/tired.h \
 ../threads/system.h ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
stats.o: ../machine/stats.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/stats.h
timer.o: ../machine/timer.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/timer.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/tired.h ../threads/system.h ../threads/alarm.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
alarm.o: ../threads/alarm.cc /usr/include/stdc-predef.h \
 ../threads/alarm.h ../machine/timer.h ../threads/copyright.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../threads/tired.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
tired.o: ../threads/tired.cc /usr/include/stdc-predef.h \
 ../threads/tired.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/bits/libc-header-start.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/bits/long-double.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/alarm.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
comm.o: ../threads/comm.cc /usr/include/stdc-predef.h ../threads/comm.h \
 ../threads/thread.h ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/synch.h ../threads/list.h \
 ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/tired.h ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
addrspace.o: ../userprog/addrspace.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/tired.h \
 ../threads/system.h ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc ../userprog/addrspace.h \
 ../userprog/bitmap.h ../userprog/../filesys/openfile.h ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../userprog/bitmap.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../userprog/../filesys/openfile.h
exception.o: ../userprog/exception.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/tired.h \
 ../threads/system.h ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc ../userprog/syscall.h
progtest.o: ../userprog/progtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../threads/tired.h \
 ../threads/system.h ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc ../machine/console.h \
 ../userprog/addrspace.h ../threads/synch.h
console.o: ../machine/console.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/console.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/tired.h ../threads/system.h ../threads/alarm.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
machine.o: ../machine/machine.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/translate.h ../machine/disk.h ../threads/system.h \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/tired.h ../threads/system.h ../threads/alarm.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
mipssim.o: ../machine/mipssim.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/translate.h ../machine/disk.h ../machine/mipssim.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../threads/tired.h ../threads/system.h \
 ../threads/alarm.h /usr/include/c++/9/vector \
 /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
translate.o: ../machine/translate.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/system.h \
 ../threads/utility.h ../threads/thread.h ../machine/machine.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../threads/tired.h ../threads/system.h ../threads/alarm.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc
syscall.o: ../userprog/syscall.cc /usr/include/stdc-predef.h \
 ../userprog/../filesys/filesys.h ../threads/copyright.h \
 ../userprog/../filesys/openfile.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/bits/long-double.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h \
 /usr/lib64/gcc/x86_64-suse-linux/9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/bits/types/__mbstate_t.h ../threads/stdarg.h \
 /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h \
 /usr/include/string.h /usr/include/bits/types/locale_t.h \
 /usr/include/bits/types/__locale_t.h /usr/include/strings.h \
 ../userprog/../filesys/openfile.h ../userprog/../machine/machine.h \
 ../userprog/../machine/translate.h ../userprog/../machine/disk.h \
 ../userprog/../threads/system.h ../userprog/../threads/copyright.h \
 ../userprog/../threads/utility.h ../userprog/../threads/thread.h \
 ../machine/machine.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../userprog/../threads/scheduler.h ../userprog/../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../userprog/../threads/tired.h \
 ../userprog/../threads/system.h ../userprog/../threads/alarm.h \
 /usr/include/c++/9/vector /usr/include/c++/9/bits/stl_algobase.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++config.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/os_defines.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/cpu_defines.h \
 /usr/include/c++/9/bits/functexcept.h \
 /usr/include/c++/9/bits/exception_defines.h \
 /usr/include/c++/9/bits/cpp_type_traits.h \
 /usr/include/c++/9/ext/type_traits.h \
 /usr/include/c++/9/ext/numeric_traits.h \
 /usr/include/c++/9/bits/stl_pair.h /usr/include/c++/9/bits/move.h \
 /usr/include/c++/9/bits/concept_check.h /usr/include/c++/9/type_traits \
 /usr/include/c++/9/bits/stl_iterator_base_types.h \
 /usr/include/c++/9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/9/debug/assertions.h \
 /usr/include/c++/9/bits/stl_iterator.h \
 /usr/include/c++/9/bits/ptr_traits.h /usr/include/c++/9/debug/debug.h \
 /usr/include/c++/9/bits/predefined_ops.h \
 /usr/include/c++/9/bits/allocator.h \
 /usr/include/c++/9/x86_64-suse-linux/bits/c++allocator.h \
 /usr/include/c++/9/ext/new_allocator.h /usr/include/c++/9/new \
 /usr/include/c++/9/exception /usr/include/c++/9/bits/exception.h \
 /usr/include/c++/9/bits/exception_ptr.h \
 /usr/include/c++/9/bits/cxxabi_init_exception.h \
 /usr/include/c++/9/typeinfo /usr/include/c++/9/bits/hash_bytes.h \
 /usr/include/c++/9/bits/nested_exception.h \
 /usr/include/c++/9/bits/memoryfwd.h \
 /usr/include/c++/9/bits/stl_construct.h \
 /usr/include/c++/9/ext/alloc_traits.h \
 /usr/include/c++/9/bits/alloc_traits.h \
 /usr/include/c++/9/bits/stl_uninitialized.h \
 /usr/include/c++/9/bits/stl_vector.h /usr/include/c++/9/initializer_list \
 /usr/include/c++/9/bits/stl_bvector.h \
 /usr/include/c++/9/bits/functional_hash.h \
 /usr/include/c++/9/bits/range_access.h \
 /usr/include/c++/9/bits/vector.tcc ../userprog/../threads/thread.h \
 ../userprog/syscall.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
