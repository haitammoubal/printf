CC := gcc
W := -c -Wall -Werror -Wextra
CFILES := ft_printf.c cal_int.c cal.c ft_detect1.c ft_detect2.c ft_detect3.c ft_putstr.c ft_sep.c 
OFILES := ${CFILES:.c=.o}
NAME := libftprintf.a
INC := ft_printf.h
CBONUS := ft_printf_bonus.c cal_int.c cal.c ft_detect1.c ft_detect2.c ft_detect3.c ft_putstr.c ft_sep.c ft_strncmp.c ft_detect_bonus.c
OBONUS := ${CBONUS:.c=.o}
${NAME} : ${OFILES} ${INC}
	@${CC} ${W} ${CFILES}
	@ar -rc ${NAME} ${OFILES}
clean :
	@rm -f  ${OFILES}
fclean : clean
	@rm -f ${NAME}
re : fclean all
all : ${NAME}
bonus : ${OBONUS} ${INC}
	@${CC} ${W} ${CBONUS}
	@ar -rc ${NAME} ${OBONUS}
