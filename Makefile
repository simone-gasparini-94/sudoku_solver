CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Iinc

BIN		= sudoku
OBJ_DIR	= obj

SRCS	= src/main.c		\
		  src/parse.c

OBJS    = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(BIN)

$(BIN): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ 

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:
	@rm -rf $(OBJ_DIR) $(BIN)

re: fclean all

