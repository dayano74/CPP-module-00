NAME := phonebook
CPP := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -f

SRCS := phonebook.cpp \

all : $(NAME)

$(NAME): $(SRCS)
		$(CPP) $(CPPFLAGS) $^ -o $@

clean :
		$(RM) $(NAME)

re : clean all

.PHONY : all clean re
