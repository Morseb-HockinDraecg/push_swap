INC_DIR	:= inc/
OBJ_DIR	:= obj/
BIN_DIR	:= bin/

NAME_C	:= $(BIN_DIR)checker
SRC_C_DIR	:= src_checker/
SRC_C	:= $(SRC_C_DIR)checker.c
OBJ_C	:= $(SRC_C:$(SRC_C_DIR)%.c=$(OBJ_DIR)%.o)

NAME_P	:= $(BIN_DIR)push_swap
SRC_P_DIR	:= src_push_swap/
SRC_P	:= $(SRC_P_DIR)push_swap.c \
	$(SRC_P_DIR)instr1.c \
	$(SRC_P_DIR)instr2.c \
	$(SRC_P_DIR)instr3.c \
	$(SRC_P_DIR)utils_ps.c \
	$(SRC_P_DIR)ez_algo.c
OBJ_P	:= $(SRC_P:$(SRC_P_DIR)%.c=$(OBJ_DIR)%.o)

SRC_DIR	:= src/
SRC	:= $(SRC_DIR)error_check.c \
	$(SRC_DIR)instruc1.c \
	$(SRC_DIR)instruc2.c \
	$(SRC_DIR)instruc3.c \
	$(SRC_DIR)get_next_line_utils.c \
	$(SRC_DIR)get_next_line.c \
	$(SRC_DIR)utils1.c 
OBJ	:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
INCLUDE	:= -Iinc
# LDFLAGS	:= -g3 -fsanitize=address

all: $(NAME_P) $(NAME_C)
	$(info -------rdy-------)
	$(info -----------------)

$(NAME_P): $(OBJ) $(OBJ_P)| $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(NAME_C): $(OBJ) $(OBJ_C)| $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)%.o: $(SRC_P_DIR)%.c $(INC_DIR)push_swap.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_C_DIR)%.c $(INC_DIR)checker.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)utils.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) -rf $(BIN_DIR)

re: fclean $(BIN_DIR) $(OBJ_DIR) all

.PHONY: all clean fclean re
.SILENT: