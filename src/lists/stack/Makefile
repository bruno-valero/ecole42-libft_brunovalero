NAME = libft.a
DOUBLE_LIST = src/lists/double_list/libdouble_list.a
INCLUDES = -I src/lists/double_list
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 $(INCLUDES)
FUNCTIONS = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ := $(FUNCTIONS:%.c=%.o)

all: $(NAME)

# DEPENDENCIES
$(DOUBLE_LIST):
	@make -C $(shell dirname $@)

$(NAME): $(OBJ) $(DOUBLE_LIST)
	@$(eval DOUBLE_LIST_OBJS := $(shell ar -t $(DOUBLE_LIST)))
	@ar rcs $(NAME) $(OBJ) $(addprefix libft/, $(DOUBLE_LIST_OBJS))

%.a:
	make -C $(dirname $@)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re so
