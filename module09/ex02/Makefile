NAME	= PmergeMe
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
IFLAGS	= -I headers

SRCS = main.cpp \
       sources/PmergeMe.cpp

OBJ_DIR = obj
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
