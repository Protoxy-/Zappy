##
## Makefile for Makefile in /home/arramo_a/rendu/zappy/src/client
## 
## Made by Alexandre ARRAMON
## Login   <arramo_a@epitech.net>
## 
## Started on  Thu Jul  2 20:09:28 2015 Alexandre ARRAMON
## Last update Sun Jul  5 21:23:31 2015 Alexandre ARRAMON
##

CXX	= g++

RM	= rm -f

SRC_FDR = .

SRC	= $(SRC_FDR)/Client.cpp \
	  $(SRC_FDR)/IA.cpp \
	  $(SRC_FDR)/Parser.cpp \
	  $(SRC_FDR)/IACommands.cpp

SRC_MAIN = $(SRC_FDR)/main.cpp

OBJ	= $(SRC:.cpp=.o)
OBJ_M = $(SRC_MAIN:.cpp=.o)

NAME	= ../../zappy_ai

CPPFLAGS += -W -Wall -Wextra -I../../include/client -std=c++11

$(NAME):$(OBJ) $(OBJ_M)
	$(CXX) -o $(NAME) $(OBJ) $(OBJ_M) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(SRC_FDR)/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all
