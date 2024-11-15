NAME = Bureaucrat

CC = c++ -Wall -Wextra -Werror -std=c++98 -g3
MAKEFLAGS += --no-print-directory

GREEN := \e[32m
RESET :=\e[0m

SRCS = Bureaucrat.cpp main.cpp

OBJS_PATH = objs/

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:%.cpp=%.o))

all: $(NAME)

$(OBJS_PATH)%.o: %.cpp
	@mkdir -p $(OBJS_PATH)
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\nCompilation Bureaucrat: $(GREEN)success$(RESET)\n"
	$(CC) $(OBJS) -o $(NAME)

clean:
	/bin/rm -rf $(OBJS) $(OBJS_PATH)
	@echo "\nBureaucrat removed: $(GREEN)success$(RESET)\n"

fclean:	clean
	/bin/rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
