# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:46:25 by qrosa             #+#    #+#              #
#    Updated: 2019/01/08 15:02:37 by qrosa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#																			   #
#						-- MAKEFILE for C++ Pool --							   #
#																			   #
################################################################################

#	ROOT_PATH && DIRECTORIES

PATH_SOURCES	=		./

# PATH_SUB_FOLDER	=		$(PATH_SOURCES)sub_folder/

################################################################################

#	FILES DECLARATIONS
SRCS			=	$(PATH_SOURCES)main.cpp \
					$(PATH_SOURCES)Pony.cpp

# SRCS_SUB_FOLDER =	$(PATH_SUBFOLDER)sub_function.c

################################################################################

#	Object Rules Declarations
OBJ			=	$(SRCS:.cpp=.o) \

#				$(SRCS_SUB_FOLDER:.cpp=.o)

# Lib includes
INC			=	-I ./

# Options can be changed
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS_OBJ	=	-Wall -Wextra -Werror
CC			=	clang++
NAME		=	pony

# Sweet colors just for swag :)
RED			=	\033[0;31m
BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
YELLOW		=	\033[0;33m
GREEN		=	\033[1;32m
NC			=	\033[0m

################################################################################

#	Make Rules
all: 			$(NAME)

debug:
				$(eval CFLAGS_OBJ += -DDEBUG)

db: 			debug all

$(NAME): 		$(OBJ) Makefile
				@echo "${BLUE}-- Linking $(NAME)${NC}"
				@$(CC) $(OBJ) $(CFALGS) -o $(NAME) $(INC)

%.o: %.c
				@echo "${CYAN}Compiling $^ into $@ ${NC}";
				@$(CC) -c $^ -o $@ $(CFLAGS_OBJ) $(INC)

clean:
				@echo "${YELLOW}-- Delete Objs In Progress${NC}";
				@rm -f $(OBJ)
				@echo "${RED}-- Delete Objs			OK${NC}";

fclean: 		clean
				@rm -f $(NAME)
				@echo "${RED}-- Delete Name			OK${NC}";

oclean:
				@echo "${RED}-- Delete Objs			OK${NC}";
				@rm -f $(OBJ)

onclean:
				@rm -f $(OBJ)
				@echo "${RED}-- Delete Objs			OK${NC}";
				@rm -f $(NAME)
				@echo "${RED}-- Delete Name			OK${NC}";

re: 			fclean all

res:			onclean all oclean

rdb: 			fclean db

.PHONY: 		all clean fclean oclean re db res rdb
