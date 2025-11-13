NAME	= Brain
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       source/AAnimal.cpp \
       source/Dog.cpp \
       source/Cat.cpp \
       source/Brain.cpp

HEADERS = headers/AAnimal.hpp \
          headers/Dog.hpp \
          headers/Cat.hpp \
          headers/Brain.hpp

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
