# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 21:25:28 by thblack-          #+#    #+#              #
#    Updated: 2025/06/10 15:59:54 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = get_next_line.c get_next_line_utils.c
B_SOURCES = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJECTS = $(SOURCES:.c=.o)
B_OBJECTS = $(B_SOURCES:.c=.o)
HEADER = get_next_line.h
NAME = program
BONUS = b_program

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

bonus: $(BONUS)

$(BONUS): $(B_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(B_OBJECTS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
