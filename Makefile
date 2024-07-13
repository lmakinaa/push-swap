# Colors
GREEN=$(shell tput setaf 2)
RED=$(shell tput setaf 1)
NC=$(shell tput sgr0)

CC=cc
CFLAGS=-Werror -Wextra -Wall
HEADER_H=./includes/helpers.h
LIST_HEADER_H=./includes/list_control.h
HELPERS_O=helpers/args_parsing.o\
			helpers/check_sorted.o\
			helpers/custom_atoi.o\
			helpers/fail_exit.o\
			helpers/ft_abs.o\
			helpers/ft_isdigit.o\
			helpers/ft_numbase_len.o\
			helpers/ft_printf.o\
			helpers/ft_putaddr.o\
			helpers/ft_putchar.o\
			helpers/ft_putendl_fd.o\
			helpers/ft_puthex.o\
			helpers/ft_putnbr.o\
			helpers/ft_putstr.o\
			helpers/ft_putstr_fd.o\
			helpers/ft_split.o\
			helpers/ft_strcmp.o\
			helpers/get_next_line.o\
			helpers/get_next_line_utils.o\
			helpers/processing_args.o\
			helpers/rrx.o\
			helpers/some_cleaning.o\
			helpers/str_arrays_join.o\
			helpers/sx_px.o
LIST_CONTROL_O=list_control/array_to_list.o\
			list_control/c_list.o\
			list_control/c_node.o\
			list_control/l_addafter.o\
			list_control/l_addback.o\
			list_control/l_addbefore.o\
			list_control/l_addfront.o\
			list_control/l_copy.o\
			list_control/l_delnode.o\
			list_control/l_display.o\
			list_control/l_free.o\
			list_control/l_len.o
CHECKER_O=checker_bonus/check_ok_or_ko.o\
		checker_bonus/instructions_check.o\
		checker_bonus/main.o\
		checker_bonus/reading_input.o
PS_O=srcs/fix_stack.o\
	srcs/list_indexing.o\
	srcs/main.o\
	srcs/maymknch_sort.o\
	srcs/maymknch_sort_utils.o\
	srcs/moves.o\
	srcs/sort_tolati.o\
	srcs/sorting.o
BONUS_NAME=checker
NAME=push_swap

all: $(NAME) bonus

bonus: $(BONUS_NAME)

$(NAME): $(HELPERS_O) $(LIST_CONTROL_O) $(PS_O)
	@$(CC) $(CFLAGS) $^ -o push_swap
	@echo "${GREEN}Done building ${NAME}!${NC}"

$(BONUS_NAME): $(HELPERS_O) $(CHECKER_O) $(LIST_CONTROL_O)
	@$(CC) $(CFLAGS) $^ -o checker
	@echo "${GREEN}Done building ${BONUS_NAME}!${NC}"

%.o: %.c $(HEADER_H) $(LIST_HEADER_H)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(CHECKER_O) $(HELPERS_O) $(LIST_CONTROL_O) $(PS_O)
	@echo "${RED}Done removing object files.${NC}"

fclean: clean
	@rm -f $(BONUS_NAME) $(NAME)
	@echo "${RED}Done removing ${NAME}.${NC}"
	@echo "${RED}Done removing ${BONUS_NAME}.${NC}"

re: fclean all

.PHONY: clean
