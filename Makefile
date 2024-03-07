# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 13:40:15 by gachalif          #+#    #+#              #
#    Updated: 2024/03/06 12:19:34 by gachalif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

SRCS_DIR = srcs
SRCS =\
		$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/input.c \
		$(SRCS_DIR)/sort.c \
\
		$(SRCS_DIR)/utils/input_utils.c \
		$(SRCS_DIR)/utils/sort_utils.c \
\
		$(SRCS_DIR)/moves/pa.c \
		$(SRCS_DIR)/moves/pb.c \
		$(SRCS_DIR)/moves/ra.c \
		$(SRCS_DIR)/moves/rb.c \
		$(SRCS_DIR)/moves/rr.c \
		$(SRCS_DIR)/moves/rra.c \
		$(SRCS_DIR)/moves/rrb.c \
		$(SRCS_DIR)/moves/rrr.c \
		$(SRCS_DIR)/moves/sa.c \
		$(SRCS_DIR)/moves/sb.c \
		$(SRCS_DIR)/moves/ss.c \
\
		$(SRCS_DIR)/libs/stacks.c \
		$(SRCS_DIR)/libs/stacks_2.c \
		$(SRCS_DIR)/libs/ft_split.c \
		$(SRCS_DIR)/libs/ft_atoi.c \

INCLUDES = -I includes \

OBJS = $(SRCS:.c=.o)

UP		= "\033[1F"
CLR		= "\033[2K"
YELLOW	= "\033[33;1m"
CYAN	= "\033[36;1m"
GREEN	= "\033[32;1m"
DEFAULT	= "\033[0;0m"

define HEADER
            █████            
        ████     ████        
    ████             ████      ██████  ██    ██ ███████ ██   ██         ███████ ██     ██  █████  ██████  
 ████                   ████   ██   ██ ██    ██ ██      ██   ██         ██      ██     ██ ██   ██ ██   ██ 
██                         ██  ██████  ██    ██ ███████ ███████         ███████ ██  █  ██ ███████ ██████  
 ████                   ████   ██      ██    ██      ██ ██   ██              ██ ██ ███ ██ ██   ██ ██      
 ███████▓           ████████   ██       ██████  ███████ ██   ██ ███████ ███████  ███ ███  ██   ██ ██      
██      ░███     ███░      ██  
 ████       █████       ████   \033[36;1mMarch 2024                                              gachalif @42Quebec\033[32;1m
 ███████             ███████ 
██      ████     ████      ██
 ████      ░█████▒      ████ 
    ████             ████    
       ░████     ████        
           ███████           
\033[0;1m
Generate solution:
        ./push_swap int_1 int_2 [...]\033[0;0m
endef
export HEADER

all: $(NAME)
		@		echo $(GREEN)
		@		echo "$$HEADER"
		@		echo $(DEFAULT)

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
		@	make all

.PHONY = all clean fclean re debug