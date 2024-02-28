# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 13:40:15 by gachalif          #+#    #+#              #
#    Updated: 2024/02/28 13:56:06 by gachalif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

SRCS_DIR = srcs
SRCS = 	$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/stacks.c \
		$(SRCS_DIR)/radix.c \

INCLUDES = -I includes \

OBJS = $(SRCS:.c=.o)

UP		= "\033[1F"
CLR		= "\033[2K"
YELLOW	= "\033[33;1m"
GREEN	= "\033[32;1m"
DEFAULT	= "\033[0;0m"


all: $(NAME)

%.o:	%.c
		@ echo $(UP)$(CLR)🔥 $(YELLOW)$@ 
		@ $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

			 
$(NAME):	$(OBJS)
			@ echo $(UP)$(CLR)🔥 $@ 
			@ $(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
			@ echo $(UP)$(CLR)✅ $(GREEN)$@ built!$(DEFAULT)

debug:	CFLAGS += -g
debug:	clean all
		@	echo $(UP)$(CLR)🐛 $(GREEN)$(NAME) built for debug!$(DEFAULT)

clean:
		@	rm -f $(OBJS)
		@	echo 🧽 $(GREEN)All clean!$(DEFAULT)

fclean: 
		@	rm -f $(OBJS) $(NAME)
		@	echo 🧽 $(GREEN)All f...clean!$(DEFAULT)

re:	
		@	rm -f $(OBJS) $(NAME)
		@	echo 🛠$(YELLOW) REBUILDING
		@	echo 
		@	make $(NAME)
		@	echo $(UP)$(UP)$(CLR)✅ $(GREEN)$(NAME) rebuilt!$(DEFAULT)

.PHONY = all clean fclean re debug