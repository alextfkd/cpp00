NAME = ex02

CXX = c++ -g

SRCS = tests.cpp Account.cpp

OBJS = $(addprefix ./, $(SRCS:.cpp=.o))

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

cppformat:
	clang-format -i $(SRCS) *.hpp

cpplint:
	clang-tidy-12 --config-file=.clang-tidy --warnings-as-errors=* --quiet Account.cpp -- -Wall -Wextra -Werror -std=c++98

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re cppformat cpplint
