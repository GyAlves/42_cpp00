NAME	= Form
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp \
       source/Bureaucrat.cpp \
       source/AForm.cpp \
       source/ShrubberyCreationForm.cpp \
       source/RobotomyRequestForm.cpp \
       source/PresidentialPardonForm.cpp
HEADERS = headers/Bureaucrat.hpp \
          headers/AForm.hpp \
          headers/ShrubberyCreationForm.hpp \
          headers/RobotomyRequestForm.hpp \
          headers/PresidentialPardonForm.hpp
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
	$(RM) *_shrubbery
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
