CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

SRCS_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_strlenc.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c get_next_line.c get_next_line_utils.c

OBJ_DIR = ./obj/
OBJ_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

INCLUDE_DIR = ./include/
INLCUDE_FILES = libft.h get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR)%.o:./%.c $(INCLUDE_FILES)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
