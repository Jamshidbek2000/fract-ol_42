# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jergashe <jergashe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 11:33:08 by jergashe          #+#    #+#              #
#    Updated: 2022/12/31 20:01:05 by jergashe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Ofast
MLX42 = MLX42/libmlx42.a
GLFW3 = MLX42/glfw_lib/libglfw3.a
LIBFT = libft_42/libft.a
SRCS = functions/fractol.c \
		functions/fractols/mandelbrot.c \
		functions/fractols/julia.c	\
		functions/fractols/burning_ship.c	\
		functions/draw/draw_mandelbrot.c \
		functions/draw/draw_julia.c	\
		functions/draw/draw_burning_ship.c	\
		functions/hooks/keyboard_mandelbrot.c \
		functions/hooks/keyboard_julia.c	\
		functions/hooks/keyboard_burning_ship.c	\
		functions/hooks/hooks.c	\
		functions/hooks/zoom.c	\
		functions/hooks/move.c	\
		functions/color/color.c	\
		functions/color/colors_1.c	\
		functions/color/colors_2.c	\
		functions/utils/utils.c	\
		functions/utils/terminate.c	\
		functions/utils/init.c	\
		functions/utils/instructons.c	\
		
OBJS = $(SRCS:.c=.o)

# colors for echo messages
DEF_COLOR = \033[0;39m
RED = \033[1;91m
GREEN = \033[4;92m
CYAN = \033[1;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m 

all: $(NAME)

# compiling 
$(NAME):$(MLX42) $(OBJS) $(GLFW3) $(LIBFT)
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)$(NAME)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) \
	$(MLX42) $(GLFW3) -framework Cocoa -framework OpenGL -framework IOKit
	@echo "$(PURPLE)$(NAME) $(DEF_COLOR)$(GREEN)Compiling done.$(DEF_COLOR)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)LIBFT. $(DEF_COLOR)"
	make -C ./libft_42
	@echo "$(PURPLE)LIBFT $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

# compiling MLX42
$(MLX42):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN) MLX42.$(DEF_COLOR)"
	git submodule update --init --recursive
	make -C ./MLX42
	@echo "$(PURPLE)MLX42 $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

# downloading, installing and moving GLFW to the correct folder if ther is none
$(GLFW3):
	@if [ -d ./MLX42/glfw_lib ]; \
	then echo "$(GREEN)./MLX42/glfw_lib Exists, no further action required.$(DEF_COLOR)"; \
	else \
	echo "$(RED)./MLX42/glfw_lib Doesn't exists.$(DEF_COLOR)"; \
	echo "$(YELLOW)Downloading and Installing GLFW3.$(DEF_COLOR)"; \
	git submodule update --init --recursive --remote && \
	curl -LO https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip && \
	unzip glfw-3.3.8.bin.MACOS.zip && \
    rm glfw-3.3.8.bin.MACOS.zip && \
	mv glfw-3.3.8.bin.MACOS/lib-universal glfw-3.3.8.bin.MACOS/glfw_lib && \
	mv glfw-3.3.8.bin.MACOS/glfw_lib ./MLX42/ && \
	mv glfw-3.3.8.bin.MACOS/include/GLFW ./MLX42/include && \
	rm -rf glfw-3.3.8.bin.MACOS && \
	echo "$(GREEN)./MLX42/glfw_lib is installed.$(DEF_COLOR)"; \
	fi

clean:
	@echo "$(RED)Removing .o files.$(DEF_COLOR)"
	$(RM) $(OBJS)
	make clean -C ./libft_42
	make clean -C ./MLX42
	@echo "$(CYAN)MLX42, fractol .o files has been removed.$(DEF_COLOR)"

fclean:
	@echo "$(RED)Deleting objects.$(DEF_COLOR)"
	$(RM) $(OBJS) $(NAME)
	make fclean -C ./libft_42
	make fclean -C ./MLX42
	rm -rf MLX42/glfw_lib/ MLX42/include/GLFW/
	@echo "$(CYAN)MLX42, fractol .o & .a files and GLFW has been removed.$(DEF_COLOR)"

re: fclean all
	@echo "$(YELLOW)Project has been rebuilt!$(DEF_COLOR)"

.PHONY: all clean fclean re