# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 21:03:05 by nel-yama          #+#    #+#              #
#    Updated: 2025/04/22 22:21:49 by nel-yama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Files
SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS_SRC = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
	ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c


OBJ_FILES = $(SRC_FILES:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = libft.a
HEADER = libft.h

# Rules
.PHONY: all clean fclean re bonus

# Default rule: make all will call make libft.a
all: $(NAME)

# Create the mandatory part of library libft.a
$(NAME): $(OBJ_FILES)
	@echo "Creating library $@"
	@ar rcs $@ $^

# Bonus rule (only includes bonus files)
bonus: $(OBJ_FILES) $(BONUS_OBJ)
	@echo "Adding bonus objects to $(NAME)"
	@ar rcs $(NAME) $^

# Compile source files (depend on libft.h)
%.o: %.c $(HEADER)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

# Remove object files
clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ_FILES) $(BONUS_OBJ)

# Remove object files and the library
fclean: clean
	@echo "Cleaning the library..."
	@rm -f $(NAME)

# Rebuild the library
re: fclean all
