CC=cc
CFLAGS=-Werror -Wextra -Wall
CHECKER_DIR=./checker_bonus
HELPERS_DIR=./helpers
LIST_CONTROL_DIR=./list_control
HEADER_H=./includes/helpers.h
HELPERS_O=$(HELPERS_DIR)/ft_printf.o $(HELPERS_DIR)/ft_putchar.o $(HELPERS_DIR)/ft_putnbr.o $(HELPERS_DIR)/ft_putstr.o\
	$(HELPERS_DIR)/ft_putaddr.o $(HELPERS_DIR)/ft_puthex.o $(HELPERS_DIR)/ft_numbase_len.o $(HELPERS_DIR)/custom_atoi.o\
	$(HELPERS_DIR)/ft_isdigit.o $(HELPERS_DIR)/ft_putstr_fd.o $(HELPERS_DIR)/fail_exit.o $(HELPERS_DIR)/args_parsing.o\
	$(HELPERS_DIR)/get_next_line.o $(HELPERS_DIR)/get_next_line_utils.o $(HELPERS_DIR)/reading_input.o\
	$(HELPERS_DIR)/instructions_check.o $(HELPERS_DIR)/ft_split.o $(HELPERS_DIR)/ft_strcmp.o $(HELPERS_DIR)/processing_args.o\
	$(HELPERS_DIR)/rrx.o $(HELPERS_DIR)/sx_px.o $(HELPERS_DIR)/check_ok_or_ko.o
LIST_CONTROL_O=$(LIST_CONTROL_DIR)/c_list.o $(LIST_CONTROL_DIR)/c_node.o $(LIST_CONTROL_DIR)/l_addafter.o $(LIST_CONTROL_DIR)/l_addback.o\
	$(LIST_CONTROL_DIR)/l_addbefore.o $(LIST_CONTROL_DIR)/l_addfront.o $(LIST_CONTROL_DIR)/l_display.o $(LIST_CONTROL_DIR)/l_free.o\
	$(LIST_CONTROL_DIR)/l_delnode.o $(LIST_CONTROL_DIR)/l_len.o $(LIST_CONTROL_DIR)/array_to_list.o
CHECKER_O=$(CHECKER_DIR)/main.o
BONUS_NAME=checker

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(HELPERS_O) $(CHECKER_O) $(LIST_CONTROL_O)
	$(CC) $(CFLAGS) $^ -o checker

$(CHECKER_DIR)/%.o: $(CHECKER_DIR)/.c $(HEADER_H)
	$(CC) $(CFLAGS) -c $<

$(HELPERS_DIR)/%.o: $(HELPERS_DIR)/.c $(HEADER_H)
	$(CC) $(CFLAGS) -c $<

$(LIST_CONTROL_DIR)/%.o: $(LIST_CONTROL_DIR)/.c $(HEADER_H)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(CHECKER_O) $(HELPERS_O) $(LIST_CONTROL_O)

fclean: clean
	rm -f $(BONUS_NAME)
