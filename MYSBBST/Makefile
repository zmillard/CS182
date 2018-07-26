NAME = MYSBBST
TARBALL = bewchy-$(NAME).tar.gz
SRC = comparators.cpp main.cpp MySBBST.hh add.cpp search.cpp remove.cpp print.cpp balancing.cpp size.cpp
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


