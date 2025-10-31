NAME	= phonebook
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS = Main.cpp source/Contact.cpp source/PhoneBook.cpp
HEADERS = headers/Contact.hpp headers/PhoneBook.hpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re