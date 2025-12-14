NAME = ex01

CC = c++ -g
GCC = g++ -g

SRCS = main.cpp PhoneBook.cpp Contact.cpp 

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): cpplint hpplint
	$(CC) $(CFLAGS) $(SRCS) -o $@ 

$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

cppformat:
	clang-format -i *.cpp

hppformat:
	clang-format -i *.hpp

cpplint: cppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet *.cpp -- -Wall -Wextra -Werror -std=c++98 
		
hpplint: hppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet *.hpp -- -Wall -Wextra -Werror -std=c++98 

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: install uninstall cppformat hppformat cpplint hpplint
