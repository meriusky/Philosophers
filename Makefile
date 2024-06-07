# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 16:34:43 by mehernan          #+#    #+#              #
#    Updated: 2024/06/07 17:38:03 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

SRCS = main.c thread_management.c print_time.c utils.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

FLAGS = -Wall -Werror -Wextra -lpthread -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all  clan fclean re
