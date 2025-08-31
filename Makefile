# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-yama <nel-yama@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 21:03:05 by nel-yama          #+#    #+#              #
#    Updated: 2025/08/31 17:28:27 by nel-yama         ###   ########.fr        #
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
	ft_split_str.c ft_split_smart.c \
	ft_split_smart_helper.c ft_split_smart_helper_2.c \
	ft_isspace.c ft_str_has_whitespace.c ft_is_str_unique.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_put_hex_llnbr.c ft_putnbr_base.c \
	ft_put_unsigned_nbr_base.c ft_put_unsigned_nbr.c \
	ft_lstadd_back.c ft_lstadd_front.c \
	ft_lstlast.c ft_lstnew.c ft_lstsize.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c

#BONUS_SRC = ft_lstadd.c ft_lstadd_front.c \
#	ft_lstlast.c ft_lstnew.c ft_lstsize.c \
#	ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
#	ft_lstmap.c


OBJ_FILES = $(SRC_FILES:.c=.o)
#BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = libft.a
HEADER = libft.h

# Rules
.PHONY: all clean fclean re #bonus

# Default rule: make all will call make libft.a
all: $(NAME)

# Create the mandatory part of library libft.a
$(NAME): $(OBJ_FILES)
	@echo "Creating library $@"
	@ar rcs $@ $^

# Bonus rule (only includes bonus files)
#bonus: $(OBJ_FILES) $(BONUS_OBJ)
#	@echo "Adding bonus objects to $(NAME)"
#	@ar rcs $(NAME) $^

# Compile source files (depend on libft.h)
%.o: %.c $(HEADER)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

# Remove object files
clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ_FILES) #$(BONUS_OBJ)

# Remove object files and the library
fclean: clean
	@echo "Cleaning the library..."
	@rm -f $(NAME)

# Rebuild the library
re: fclean all
