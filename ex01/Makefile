NAME	= phonebook
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS = Main.cpp source/Contact.cpp source/PhoneBook.cpp utils/FormatCommandInput.cpp utils/HandleAddCommand.cpp utils/HandleSearchCommand.cpp
HEADERS = headers/Contact.hpp headers/PhoneBook.hpp headers/Utils.hpp

OBJ_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(SRCS:.cpp=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
