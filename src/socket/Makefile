# Nicholas Massa 
# Makefile for pipes

CLINAME=client
CLISRC=client.c
SERVNAME=server
SERVSRC=server.c bye.c stop_server.c disconnect.c

CLIOBJ=$(CLISRC:.c=.o)
SERVOBJ=$(SERVSRC:.c=.o)

RM=rm -f

INCLPATH=../../include
LIBPATH=../../lib
CFLAGS+= -I$(INCLPATH)
LDFLAGS+= -L$(LIBPATH)
LDLIBS+= -lmy

all: my server client

client: $(CLIOBJ)

server: $(SERVOBJ)

my:
	cd ../my && make

myfclean:
	cd ../my && make fclean

myclean:
	cd ../my && make clean

clean: myclean
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: myfclean clean
	-$(RM) $(CLINAME)
	-$(RM) $(SERVNAME)

re: fclean all
