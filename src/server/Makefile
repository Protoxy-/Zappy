##
## Makefile for zappy in /home/alex/rendu/zappy
## 
## Made by page_a
## Login   <alex@epitech.net>
## 
## Started on  Fri May  1 17:37:47 2015 page_a
## Last update Sun Jul  5 20:49:49 2015 Maxime JUNGER
##

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
        CC = gcc-5
else
	CC = gcc
endif

CC			= gcc

NAME		= ../../zappy_server

RM			= rm -rf

MKDIR		= mkdir -p

SRCS_DIR	= ./

SRCS		= main.c \
	  		  add_read.c \
	  		  add_read_func.c \
			  tabptr.c \
			  server.c \
			  control_handling.c \
			  my_check_pointer.c \
			  graphic.c \
			  player.c \
			  token_food.c \
			  health_player.c \
			  win.c \
			  exit.c \
			  teamname.c \
			  ghost.c \
			  egg.c \
			  incantation_stop.c \
			  incantation_messages.c \
			  \
			  levels/level1_5.c \
			  levels/level6_7.c \
			  \
			  parser/parser.c \
			  parser/parser_tabptr.c \
			  parser/parser_tabptr_func.c \
			  \
			  map/map_init.c \
			  map/map_tabptr.c \
			  map/map_func_stone.c \
			  map/dec_ressources.c \
			  map/dec_ressources_func.c \
			  map/get_ressources.c \
			  map/get_ressources_func.c \
			  \
			  lib/my_str_to_wordtab.c \
			  lib/allocations.c \
			  lib/write_on_client.c \
			  lib/my_linked_list.c \
			  lib/my_linked_list_manage.c \
			  lib/linked_list_player.c \
			  lib/wait_struct.c \
			  lib/time_manager.c \
			  lib/list_wait_functions.c \
			  lib/linked_list_monitors.c \
			  lib/error_manager.c \
			  \
			  commands/bct.c \
			  commands/mct.c \
			  commands/msz.c \
			  commands/sbp.c \
			  commands/tna.c \
			  commands/pbc.c \
			  commands/plv.c \
			  commands/ppo.c \
			  commands/pex.c \
			  commands/pdr.c \
			  commands/pgt.c \
			  commands/pin.c \
			  commands/sgt.c \
			  commands/connect_nbr.c \
			  commands/see.c \
			  commands/see_func.c \
			  commands/move_on.c \
			  commands/inventory.c \
			  commands/pnw.c \
			  commands/smg.c \
			  commands/turn.c \
			  commands/pfk.c \
			  commands/eht.c \
			  commands/ebo.c \
			  commands/incantation.c \
			  \
			  sound/sound_manager.c \
			  sound/oriented_down.c \
			  sound/oriented_up.c \
			  sound/oriented_left.c \
			  sound/oriented_right.c

OBJS_DIR	= ../../obj

OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

INCS_DIR	= include

CFLAGS		+= -I../../include

CFLAGS		+= -std=gnu99 -Wall -Wextra

CPPFLAGS	+= -D_GNU_SOURCE

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c 
	@$(MKDIR) $(OBJS_DIR)
	@$(MKDIR) $(OBJS_DIR)
	@$(MKDIR) $(OBJS_DIR)/parser
	@$(MKDIR) $(OBJS_DIR)/map
	@$(MKDIR) $(OBJS_DIR)/commands
	@$(MKDIR) $(OBJS_DIR)/levels
	@$(MKDIR) $(OBJS_DIR)/lib
	@$(MKDIR) $(OBJS_DIR)/sound
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
