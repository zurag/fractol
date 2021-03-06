NAME		= fractol
CC			= gcc
RM			= rm -f
DEBUG		= 1

CFLAGS		= -Wall -Wextra -Werror -MMD $(DEBUG_FLAGS)
CPPFLAGS	= $(CFLAGS) -march=native -O2 -msse4a -flto -pipe
HEADERS		= include/

SRCS =	main.c hooks.c Mandelbrot.c Julia.c color.c Burning_ship.c fractol.c

OBJS = $(SRCS:.c=.o)

$(NAME):		$(OBJS)
				cd minilibx && $(MAKE) && mv libmlx.dylib ../libmlx.dylib
				cd libft && $(MAKE) && mv libft.a ../libft.a
				$(CC) $(CPPFLAGS) -I $(HEADERS) $(OBJS) libft.a libmlx.dylib -o $(NAME)

all:			$(NAME)

.c.o:
				$(CC) $(CPPFLAGS) -I $(HEADERS) -o $@ -c $<

$(OBJS):		$(HEADERS)

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS:.o=.d)

fclean:			clean
				cd minilibx && $(MAKE) clean
				cd libft && $(MAKE) clean
				$(RM) libmlx.dylib
				$(RM) libft.a
				$(RM) $(NAME)

re:				fclean all

re_pr:			clean all

.PHONY:			all clean fclean re re_pr