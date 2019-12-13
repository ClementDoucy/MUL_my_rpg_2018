##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	my_rpg

SRC	=	src/basic_fonction/my_basic_fonction_one.c	\
                src/basic_fonction/my_basic_fonction_two.c	\
                src/basic_fonction/string_handling.c    \
                src/error_handling/error_handling.c	\
                src/game/main.c	 \
                src/game/launch.c	\
                src/game/game.c		\
                src/game/init_game.c	\
                src/game/display_window.c	\
                src/game/create_mouse.c		\
                src/game/manage_mouse_move.c    \
		src/game/start_game.c   \
                src/game/sort_object.c   \
		src/game/manage_pnj.c   \
                src/game/init_pnj.c   \
		src/game/character_move.c \
		src/game/player_animations.c  \
                src/menu/init_sprite_menu.c	\
                src/menu/create_sprite_menu.c	\
                src/menu/create_text_menu.c	\
                src/menu/menu.c			\
                src/menu/init_position_event_menu.c \
                src/menu/display_settings_game.c    \
                src/menu/display_profil_game.c  \
                src/menu/click_button_settings.c    \
                src/menu/check_profil_and_create_name_player.c  \
                src/menu/init_profil.c  \
                src/menu/display_name_player.c  \
                src/menu/destroy_menu.c \
		src/game/init_sprite_game.c     \
                src/game/init_tree_and_house.c        \
                src/game/init_river_and_sign.c	\
                src/game/init_object.c       \
		src/game/init_player.c  \
                src/game/init_pause.c   \
		src/game/check_and_block_player.c   \
		src/game/object_collider.c	\
		src/game/inventory.c	\
		src/game/gui_init.c	\
		src/game/items.c	\
		src/game/inventory_items.c	\
		src/game/input_handling.c	\
		src/game/manage_stuff.c	\
		src/game/items_info.c	\
		src/game/init_enemy.c  \
		src/game/init_boss.c  \
		src/game/manage_enemy.c  \
		src/game/manage_boss.c  \
		src/game/boss_animations.c  \
		src/game/tools_enemy.c  \
		src/game/target_and_hit_player.c  \
                src/game/display_pause.c        \
                src/game/analyse_event_pause.c	\
		src/game/status_bar.c	\
		src/game/status_bar_init.c	\
		src/basic_fonction/tools_2.c	\
		src/game/manage_player_stat.c	\
		src/game/manage_stuff_2.c  \
		src/game/sprite_tools.c  \
		src/game/competencies.c	\
		src/game/draw_pnj.c  \
		src/game/character_manager.c	\
		src/particle/particle.c	\
		src/particle/blood.c	\
		src/game/enemy_hit.c	\
		src/game/scorpio_animation.c  \
		src/basic_fonction/int_to_str.c	\
		src/game/draw_gui_text.c   \
		src/game/get_save_fonction_in_game.c	\
		src/menu/display_resume_game.c	\
		src/menu/manage_mouse_move_settings.c	\
		src/menu/manage_mouse_click_settings.c	\
		src/menu/get_save_fonction_menu.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I ./include

CFLAGS	=	-Wextra

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:	$(NAME) save

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf src/*~
	rm -rf *~ *#
	rm -rf vgcore*
	rm -rf src/basic_fonction/*~ src/basic_fonction/*# src/game/*~ src/game/*# src/menu/*~ src/menu/*#
	rm -rf src/error_handling/*~ src/error_handling/*# include/*~ include/*# src/particle/*~ src/particle/*#

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all

run: 	all
	./my_rpg

debug: CFLAGS += -g3
debug:	fclean $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)
	valgrind ./my_rpg

save:
	if [ ! -d "./save" ]; then mkdir "./save"; fi

.PHONY:	all clean fclean re run debug save
