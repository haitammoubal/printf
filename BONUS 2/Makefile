CC := gcc
W := -c -Wall -Werror -Wextra
CFILES := ft_printf.c ft_printf_utils.c
OFILES := ${CFILES:.c=.o}
NAME := libftprintf.a
INC := ft_printf.h
CBONUS := ft_printf_bonus.c ft_printf_utils_bonus.c ft_detect_bonus_all.c \
		ft_size_hex.c ft_size_int.c ft_strlen.c ft_print_space.c \
		ft_printf_utils.c ft_calc_width_unsign.c ft_calc_width_unsign_long.c \
		ft_calc_width_str.c ft_calc_width_int.c
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
