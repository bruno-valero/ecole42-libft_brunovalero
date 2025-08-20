NAME = libft.a
# ------------------------ Dependencies -------------------------------
STACK_PATH = src/lists/stack
STACK = $(STACK_PATH)/libstack.a
# ----------
LIBSTR_PATH = src/libstr
LIBSTR = $(LIBSTR_PATH)/libstr.a
# ------------------------ Commands -------------------------------
INCLUDES = -I $(STACK_PATH)/includes -I $(LIBSTR_PATH)/includes
CC = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)
SLEEP = 0.05
# ------------------------ Paths / files -------------------------------
SRC_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c \
			ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
			ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ = obj
OBJ_FILES := $(SRC_FILES:%.c=$(OBJ)/%.o)
DEPENDENCY_OBJS = dependency_objs
DEPENDENCY_LIBS = $(STACK) $(LIBSTR)
DEPENDENCY_INCLUDES = dependency_includes

# ******************* Main targets *******************
all: $(DEPENDENCY_LIBS) $(OBJ) $(DEPENDENCY_OBJS) $(NAME)

$(NAME): $(DEPENDENCY_INCLUDES) $(OBJ_FILES)
# -------------- copying includes -----------------------------------------
	@echo ">> copying inludes from './$(STACK_PATH)' to '$(DEPENDENCY_INCLUDES)'..." && sleep $(SLEEP)
	@cp -rf $(STACK_PATH)/includes/* $(DEPENDENCY_INCLUDES)
	@echo ">> copying inludes from './$(LIBSTR_PATH)' to '$(DEPENDENCY_INCLUDES)'..." && sleep $(SLEEP)
	@cp -rf $(LIBSTR_PATH)/includes/* $(DEPENDENCY_INCLUDES)
# -------------- extracting 'files.o' -----------------------------------------
	@echo ">> extracting 'files.o' from '$(STACK)' to '$(DEPENDENCY_OBJS)'..." && sleep $(SLEEP)
	@ar x $(STACK) --output $(DEPENDENCY_OBJS)
	@echo ">> extracting 'files.o' from '$(LIBSTR)' to '$(DEPENDENCY_OBJS)'..." && sleep $(SLEEP)
	@ar x $(LIBSTR) --output $(DEPENDENCY_OBJS)
# -------------- compiling 'libft.a' -----------------------------------------
	@echo ">> compiling $@..." && sleep $(SLEEP)
	@ar rcs $@ $(OBJ_FILES) $(DEPENDENCY_OBJS)/*.o
# ****************************************************

# ------------- Dependency libs -------------
$(STACK):
	@echo ">> compiling $@..." && sleep $(SLEEP)
	@make -s -C $(STACK_PATH)

$(LIBSTR):
	@echo ">> compiling $@..." && sleep $(SLEEP)
	@make -s -C $(LIBSTR_PATH)
# --------------------------------------------

# ------------- Obrigatory files on root -------------
$(OBJ):
	@echo ">> creatting ./$@ folder..." && sleep $(SLEEP)
	@mkdir $(OBJ)

$(DEPENDENCY_OBJS):
	@echo ">> creatting ./$@ folder..." && sleep $(SLEEP)
	@mkdir $(DEPENDENCY_OBJS)

$(DEPENDENCY_INCLUDES):
	@echo ">> creatting ./$@ folder..." && sleep $(SLEEP)
	@mkdir $(DEPENDENCY_INCLUDES)
# -----------------------------------------------------

$(OBJ)/%.o: %.c
# @echo ">> compiling $< file..." && sleep $(SLEEP)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s -C $(STACK_PATH) clean
	@make -s -C $(LIBSTR_PATH) clean
	@rm -rf $(OBJ) $(DEPENDENCY_OBJS) $(DEPENDENCY_INCLUDES)

fclean: clean
	@make -s -C $(STACK_PATH) fclean
	@make -s -C $(LIBSTR_PATH) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
