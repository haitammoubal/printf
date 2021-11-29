CC := gcc
W := -c -Wall -Werror -Wextra
CFILES := ft_printf.c ft_printf_utils.c
OFILES := ${CFILES:.c=.o}
NAME := libftprintf.a
INC := ft_printf.h
CBONUS := ft_printf_bonus.c ft_printf_utils_bonus.c ft_detect_bonus_all.c \
		ft_size_hex.c ft_size_int.c ft_strlen.c ft_print_space.c \
		ft_calc_width_unsign.c ft_calc_width_unsign_long.c \
		ft_calc_width_str.c ft_calc_width_int.c ft_bonus_dot.c ft_bonus_zero.c \
		ft_bonus_minus.c ft_detect_bonus2_all.c ft_calc_width_unsign_zero.c \
		ft_calc_width_unsign_long_zero.c ft_calc_width_str_zero.c ft_calc_width_int_zero.c \
		ft_print_zero.c ft_size_unsign.c ft_calc_width_int_minus.c ft_calc_width_str_minus.c \
		ft_calc_width_unsign_long_minus.c ft_calc_width_unsign_minus.c ft_putstr_dot.c \
		ft_comb1.c ft_comb2.c ft_comb3.c ft_max_width.c ft_bonus_dotzero.c ft_bonus_dotminus.c \
		ft_calc_width_str_zero_dot.c ft_calc_width_unsign_long_space.c ft_calc_width_unsign_longr.c \
		ft_print_space_presi.c ft_calc_width_unsign_zero2.c ft_calc_width_unsign_longr_printzero.c \
		ft_calc_width_unsign_int.c ft_str_space.c ft_print_space_presi_hex.c
OBONUS := ${CBONUS:.c=.o}
${NAME} : ${OFILES} ${INC}
	@${CC} ${W} ${CFILES}
	@ar -rc ${NAME} ${OFILES}
clean :
	@rm -f  ${OFILES} ${OBONUS}
fclean : clean
	@rm -f ${NAME}
re : fclean all
all : ${NAME}
bonus : ${OBONUS} ${INC}
	@${CC} ${W} ${CBONUS}
	@ar -rc ${NAME} ${OBONUS}

debug : ${OBONUS} ${INC}
	@${CC} -g ${W} ${CBONUS}
	@ar -rc ${NAME} ${OBONUS}
	@rm -f  ${OFILES} ${OBONUS}
