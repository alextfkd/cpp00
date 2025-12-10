NAME = megaphone

CC = c++ -g
GCC = g++ -g

SRCS = megaphone.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): cpplint
	$(CC) $(CFLAGS) $(SRCS) -o $@ 

cppformat:
	clang-format -i *.cpp

hppformat:
	clang-format -i *.hpp

cpplint: cppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet *.cpp -- -Wall -Wextra -Werror -std=c++98 
		
hpplint: hppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet *.hpp -- -Wall -Wextra -Werror -std=c++98 

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: install uninstall cppformat hppformat cpplint hpplint
