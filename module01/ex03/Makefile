NAME	= UnnecessaryViolence
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp source/Weapon.cpp source/HumanA.cpp source/HumanB.cpp 
HEADERS = headers/Weapon.hpp headers/HumanA.hpp headers/HumanB.hpp

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
