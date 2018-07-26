NAME = Dungeon
TARBALL = zmillard-$(NAME).tar.gz
SRC = hero.cpp search.cpp hall.cpp room.cpp main.cpp mst.cpp print.cpp path.cpp
CPPFLAGS = -g
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: $(OBJ)
	g++ $(OBJ) -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all

submit: fclean
	tar cvzf $(TARBALL) *


