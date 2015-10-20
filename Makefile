##
## Makefile for zappy in /Users/junger_m/EPITECH/TEK2/SystemUnix/ZAPPY - DEV/ZAPPY - DEV
##
## Made by Maxime JUNGER
## Login   <junger_m@epitech.eu>
##
## Started on  Fri Jun 19 19:19:12 2015 Maxime JUNGER
## Last update Thu Jul  2 11:29:50 2015 Alexandre ARRAMON
##

DIR_SERVER = ./src/server
DIR_CLIENT = ./src/client
DIR_GRAPHIC = ./src/graphic

all: server client

server:
	make -C $(DIR_SERVER)

client:
	make -C $(DIR_CLIENT)

graphic:
	make -C $(DIR_GRAPHIC)

clean:
	make clean -C $(DIR_SERVER)
	make clean -C $(DIR_CLIENT)
	make clean -C $(DIR_GRAPHIC)

fclean:
	make fclean -C $(DIR_SERVER)
	make fclean -C $(DIR_CLIENT)
	make fclean -C $(DIR_GRAPHIC)

re: reserver reclient

reserver:
	make re -C $(DIR_SERVER)

reclient:
	make re -C $(DIR_CLIENT)

regraphic:
	make re -C $(DIR_GRAPHIC)

.PHONY: all server client graphic clean fclean re reserver reclient regraphic
