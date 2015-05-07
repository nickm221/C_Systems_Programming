NAME = libmy.a
SRC = my_char.c my_str.c my_int.c my_num_base.c my_alpha.c my_digit.c my_strlen.c my_revstr.c my_strindex.c my_strrindex.c my_strdup.c my_strcpy.c my_strncpy.c my_strcmp.c my_strncmp.c xmalloc.c my_strconcat.c my_strnconcat.c my_strcat.c my_panic.c my_strfind.c my_strrfind.c my_vect2str.c my_str2vect.c my_atoi.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS += -I$(INCLPATH)

all:$(OBJ)
	ar -rc $(LIBPATH)/$(NAME) $(OBJ)
	ranlib $(LIBPATH)/$(NAME)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean:clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all
