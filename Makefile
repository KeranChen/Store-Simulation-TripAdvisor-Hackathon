###########################################################################
##                  Makefile for Proj1 (Nozama)                    ##
###########################################################################
#
# Because this is one of the first Makefile you see, we'll put comment in 
# that explain some of what's going on.  We're not *that* nice (and we're
# kind of lazy) so we neglected to include some sections of the Makefile.
#
# You will find these numbered omissions denoted by the character 
# sequence {[i]}.
#
# In order to use this Makefile, and for us to compile and run your work 
# you will need to complete this Makefile. You will need to replace the 
# {[i]} with the correct flags, file names, etc. We suggest that you take a 
# look at the other Makefile that you received (Lab 1) and use that as a
# starting point/template to help you fill this Makefile out.
#

#
# The "make" Unix program is a powerful tool that is used to build
# software.  It can be used for lots of other things, too, but building
# programs was the main problem it was designed to solve.
# It automates the compilation and linking commands you would have to type
# by hand, which is a big help with a large program with many components!
#
# To use make, you will usually write a Makefile, like this one.  It
# contains 2 kinds of things:  variable definitions and rules.
#
# We'll first define some variables.  You can define any variables you
# like, but there are some variables that have conventional meanings.
#
# CXX is conventionally used for the C++ compiler you want to use.  
# We'll use clang++ in Comp 15, because it tends to have better error
# messages than the alternative (g++).  CPP wasn't used for C++, because
# it was already in use for something else when C++ was invented.
#
# CXXFLAGS is conventionally used for the parameters (flags) you want 
# to use whenever you compile a C++ program.  In this case, we're
# telling the compiler to leave all the debugging information it can
# in the resulting file (g3), to give us all the standard warnings
# (Wall), and to give us even MORE warnings (Wextra).
#
# LDFLAGS is conventionally used for the parameters (flags) you want
# to use when you link a bunch of program components together to make
# an executable program.  In this case, we're asking for all the
# debugging information again.
#
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra 
LDFLAGS  = -g3

#
# Here are the rules!  Each rule has a "target" followed by a colon.
# After the colon, is a list of "dependencies" (also called
# "prerequisites") all on one line.  These are files that must already
# exist and be up-to-date before you can make the target.  So, the
# first rule below says that you'd like define how to make a thing
# called "charLinkedList," and that depends on 4 .o files.  You may follow
# that line with a recipe as a series of one line commands indented
# with a tab character (yes, it must be a tab character!).  In this
# first rule, if you have all the .o files up-to-date, you make a
# hookbook by running clang++ with the flags specified above giving it
# all the .o files and producing leaving the executable output in a
# file named "charLinkedList".
# 
#
Nozama: nozama.o testNozama.o Nozama.o
	${CXX} ${LDFLAGS} -o nozama testNozama.o Nozama.o

Orderqueue: orderqueue.o Orderqueue.o
	${CXX} ${LDFLAGS} -o orderqueue \
                        Orderqueue.o

Parser: parser.o Parser.o
	${CXX} ${LDFLAGS} -o parser Parser.o

Time: time.o Time.o
	${CXX} ${LDFLAGS} -o time Time.o

Fetch: fetch.o Fetch.o
	${CXX} ${LDFLAGS} -o fetch Fetch.o

PackerManager: packerManager.o PackerManager.o
	${CXX} ${LDFLAGS} -o packerManager PackerManager.o

Packer: packer.o Packer.o
	${CXX} ${LDFLAGS} -o packer Packer.o

Statistitian: statistitian.o Statistitian.o
	${CXX} ${LDFLAGS} -o statistitian Statistitian.o
#
# The following rules don't have recipes.  The make program has a ton
# of built-in rules, and it knows that if you want a X.o file and you
# have an X.cpp, it can compile the .cpp file to make a .o file.
# Furthermore, if the conventionally known variables CXX and CXXFLAGS
# are defined, it will use them!  What it doesn't know is what files
# besides the .cpp file the program module might depend on.  So, we
# only specify the target and dependencies here.
#
testNozama.o: testNozama.cpp  Nozama.h  Orderqueue.h  Parser.h \
	Order.h  Time.h  Fetch.h  PackerManager.h  Statistitian.h \
	Packer.h 
nozama.o:     Nozama.cpp    Nozama.h  Orderqueue.h  Parser.h \
	Time.h  Fetch.h  PackerManager.h  Statistitian.h  Packer.h 
parser.o:         Parser.cpp          Parser.h        Order.h
time.o:           Time.cpp            Time.h
fetch.o:          Fetch.cpp           Fetch.h         Order.h \
	Orderqueue.h 
orderqueue.o:     Orderqueue.cpp      Orderqueue.h     Order.h 
packerManager.o:  PackerManager.cpp   PackerManager.h   Order.h \
	Orderqueue.h  Packer.h
packer.o:         Packer.cpp          Packer.h          Order.h \
	Orderqueue.h
statistitian.o:    Statistitian.cpp   Statistitian.h    Order.h \
	Orderqueue.h 



#
# The following rules show how you can use make to automate things
# besides program building.
#
# Makefiles traditionally have a "clean" target.  The purpose is to
# clean up everything that is automatically built by make.  It's
# useful for when you want to save disk space and also when you've
# messed things up and just want to rebuild everything from scratch.
# The clean target doesn't have an prerequisites, because you don't
# need anything to be there in order to clean up!
#
# .dSYM directories are something that gets make in the Mac
# environment for debugging data, and so I delete them when cleaning
# up. 
#
clean:
	rm -rf rPNCalc *.o *.dSYM

#
# You can even have a rule that turns your work in for you!
# You can make rules for running tests, too.
#
provide:
	provide comp15 proj1part2 testNozama.cpp \
                           Nozama.cpp \
                           Nozama.h \
                           Fetch.cpp \
                           Fetch.h \
                           Order.h \
                           Orderqueue.cpp \
                           Orderqueue.h \
                           Packer.cpp \
                           Packer.h \
                           PackerManager.cpp \
                           PackerManager.h \
                           Parser.cpp \
                           Parser.h \
                           Statistitian.cpp \
                           Statistitian.h \
                           Time.cpp \
                           Time.h \
                           Makefile \
                           README
