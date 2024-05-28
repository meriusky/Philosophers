# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 16:34:43 by mehernan          #+#    #+#              #
#    Updated: 2024/05/28 18:54:39 by mehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

SRCS = main.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

PRINTF =printf/libftprintf.a
all:
	@$(MAKE) $(NAME)

clean:
	rm -rf$(OBJS)
	rm -rf$(DEPS)

fclean: clean
	$(MAKE) -C printf fclean
//potser faltes coses
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all  clan fclean re
