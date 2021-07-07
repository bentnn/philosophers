NAME	=	philo

SRCS	=	srcs/main.c\
			srcs/data_func.c\
			srcs/routines.c\
			srcs/simple_func.c\
			srcs/simple_func2.c

HEADER	=	srcs/philo.h

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME): 	$(OBJS) $(HEADER)
			gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re