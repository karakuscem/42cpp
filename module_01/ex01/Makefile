NAME	=	zombie
CC		=	c++ 
CFLAG	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf
SRCS	=	Zombie.cpp \
			zombiehORDE.cpp \
			main.cpp \

OBJS	=	${SRCS:.c=.o}

all	:
	@$(MAKE)  $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAG) -o $(NAME) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@

clean :
	@$(RM)

fclean : clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY : all clean fclean re