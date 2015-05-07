# Makefile for my and mylist project
RM=rm -f
INCLPATH=../include
LIBPATH=../lib

#libmy variables
SRCMY=testmy.c
LIBMY=my
MYNAME=testmy

#libmylist variables
SRCLIST=testzero.c
LIBLIST=mylist
LISTFOLDER=list
LISTNAME=testlist

all: allclean libmy liblist

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core
	-$(RM) $(MYNAME)
	-$(RM) $(LISTNAME)

lib:
	cd ../src/$(LIBMY) && make
	cd ../src/$(LISTFOLDER) && make

libmy: lib
	cc -I$(INCLPATH) -L$(LIBPATH) $(SRCMY) -l$(LIBMY) -o $(MYNAME)

liblist: lib
	cc -I$(INCLPATH) -L$(LIBPATH) $(SRCLIST) -l$(LIBLIST) -l$(LIBMY) -o $(LISTNAME)

fclean: clean
	cd ../src/$(LIBMY) && make fclean
	cd ../src/$(LISTFOLDER) && make fclean

allclean: clean
	cd ../src/$(LIBMY) && make clean
	cd ../src/$(LISTFOLDER) && make clean
