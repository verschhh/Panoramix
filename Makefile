##
## EPITECH PROJECT, 2021
## makefile
## File description:
## i
##

SRC	=	$(shell find ./src/ -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	panoramix

NAME2	=	*.c~

LDFLAGS	=	-L -lmy

CPPFLAGS	=	-I Include/

CFLAGS =	-Wall -Wextra

MATH	=	-lm

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS) $(MATH) -pthread -lrt

debug: CFLAGS += -g3
debug: re

clean:
	$(RM) $(NAME)

fclean:	clean
	$(RM) $(OBJ)

re: fclean all

.PHONY: test_run debug clean fclean re all
