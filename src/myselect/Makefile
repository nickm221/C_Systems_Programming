NAME= myselect

SRC= myselect.c init_terminal.c restore_terminal.c init_caps.c term_get_cap.c setup_elems.c show_elems.c term_vi.c term_ve.c term_clear.c my_termprint.c refreshout.c term_standout.c term_standend.c term_move_to_item.c refreshin.c term_underline.c term_underend.c movedown.c moveup.c moveleft.c moveright.c doselect.c check_character.c getout.c
 
OBJ=$(SRC:.c=.o)

RM=rm -f

INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS += -I$(INCLPATH)
LDFLAGS += -L$(LIBPATH)
LDLIBS += -lmy -ltermcap

all: my $(NAME)

$(NAME): $(OBJ)

my:
	cd ../my; make

clean:
	-$(RM) *.o
	-$(RM) *.swp
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.core

fclean: clean
	-$(RM) $(NAME)

re: fclean all
