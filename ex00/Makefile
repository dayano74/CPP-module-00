NAME := megaphone
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -f

SRCS := megaphone.cpp
OBJS

all : $(NAME)

$(NAME): $(SRCS)
		$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) -r $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
