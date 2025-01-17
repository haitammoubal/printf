CC = gcc
W = -c -Wall -Werror -Wextra
CFILES = ft_printf.c ft_printf_utils.c
OFILES = ${CFILES:.c=.o}
NAME = libftprintf.a
INC = ft_printf.h
CBONUS = ft_printf_bonus.c ft_printf_utils_bonus.c ft_detect_bonus4_all.c ft_space_flags.c ft_plus_flags.c ft_sharp_flags.c ft_putstr.c
OBONUS = ${CBONUS:.c=.o}

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
