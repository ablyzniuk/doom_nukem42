# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/08 12:28:56 by yalytvyn          #+#    #+#              #
#    Updated: 2019/05/08 19:27:58 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= doom

SRC		=	src/*.c

SDL2_HEADER =	-I frameworks/SDL2.framework/Headers/ \
				-I frameworks/SDL2_mixer.framework/Headers/ \
				-I frameworks/SDL2_ttf.framework/Headers/

SDLFLAGS = -framework SDL2 -framework SDL2_mixer -framework SDL2_ttf -F ./frameworks

SDL2_P = -rpath @loader_path/frameworks/

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))

.SILENT:


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -g -L libft/ -lft -L/usr/local/lib -Iincludes -Ilibft/includes $(SDL2_HEADER) $(SDL2_P) $(SDLFLAGS) $(SRC)  -o $(NAME) 
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Dooms"

obj/%.o: src/%.c
	mkdir -p obj
	gcc  -Wall -Wextra -c -g -Iincludes -Ilibft/includes $(SDL2_HEADER) $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./doom3d

all: $(NAME)
.PHONY: clean fclean re all
