CC          =	gcc

# Flags that are sent to the compiler
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude

# add directory names here if you want to separate files by directories
BINDIR = bin/
SRCDIR = src/

SOURCE = $(SRCDIR)stack.c $(SRCDIR)main.c

OBJS    = stack.o main.o


#The names of the binary programs that will be produced.  
#
PROGNAME = $(BINDIR)mainrunnable


default : link

link: compile
	$(CC) -o $(PROGNAME) $(OBJS)

compile: 
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)

clean:
	@ rm *.o
	@ rm bin/*
	
run:
	cd bin; ./mainrunnable
