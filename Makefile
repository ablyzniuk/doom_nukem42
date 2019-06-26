# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/22 12:32:02 by vrudyka           #+#    #+#              #
#    Updated: 2019/06/23 15:49:20 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EDITOR := map_editor
ENGINE := doom

M_PATH := editor/
E_PATH := engine/

RED := \033[0;31m
GREEN := \033[0;32m
RESET := \033[0m

all:
	@$(MAKE) -C $(M_PATH)
	@$(MAKE) -C $(E_PATH)
	@ ln -s $(M_PATH)$(EDITOR)
	@ ln -s $(E_PATH)$(ENGINE)

clean:
	@$(MAKE) clean -C $(M_PATH)
	@$(MAKE) clean -C $(E_PATH)

fclean:
	@$(MAKE) fclean -C $(M_PATH)
	@$(MAKE) fclean -C $(E_PATH)
	@ rm -f $(EDITOR) $(ENGINE)

re: fclean all