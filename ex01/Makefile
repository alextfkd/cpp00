NAME = ex01

CXX = c++ -g

SRCS = main.cpp PhoneBook.cpp Contact.cpp 

OBJS = $(addprefix ./, $(SRCS:.cpp=.o))

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ 

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

cppformat:
	clang-format -i *.cpp *.hpp

cpplint: cppformat
	clang-tidy --config-file=.clang-tidy --warnings-as-errors=* --quiet $(SRCS) *.hpp -- -Wall -Wextra -Werror -std=c++98 

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re cppformat cpplint
