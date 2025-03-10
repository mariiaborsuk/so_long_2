SFILES			= \
				./src/display_map.c \
				./src/file_utils.c \
				./src/free_functions.c \
				./src/map.c \
				./src/maps_utils.c \
				./src/movement_utils.c \
				./src/movement.c \
				./src/utils_1.c \
				./src/utils_2.c \
				./src/validation/check_borders.c \
				./src/validation/check_collectibles.c \
				./src/validation/check_file_extension.c \
				./src/validation/check_p_e.c \
				./src/validation/check_rectangular.c \
				./src/validation/check_symbols.c \
				./src/validation/check_ways.c \
				./src/validation/check_ways_utils.c \
				./src/validation/validation.c \
				main.c
OFILES			= $(SFILES:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror -I.
# CFLAGS			= -g -Wall -Wextra -I. -fPIE

LIBS = ./lib/ft_split.c ./lib/ft_strjoin.c ./lib/ft_itoa.c
OLIBS = $(LIBS:.c=.o)

# MINILIB_LIBDIR = ../minilibx
MINILIB_LIBDIR = minilibx
MINILIB_LIBS = -L$(MINILIB_LIBDIR) -lmlx_linux -lXext -lX11

NAME			= so_long
all:			$(NAME)

$(NAME):		$(OFILES)
				$(CC) $(CFLAGS) $(LIBS) $(OFILES) $(MINILIB_LIBS) -no-pie -o $(NAME)

clean:
				$(RM) $(OFILES)

fclean:			clean
				$(RM) $(NAME) $(OLIBS)

re:				fclean $(NAME)
.PHONY:			all clean fclean re
