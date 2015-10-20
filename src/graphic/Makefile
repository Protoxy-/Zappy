##
## Makefile for Zappy
##
## Made by Hoertel Francois
## Login   <hoerte_f@epitech.eu>
##
## Started on  Thu May 21 09:46:57 2015 Hoertel Francois
## Last update Thu Jun 11 18:44:46 2015 Hoertel Francois
##

CXX				= g++

NAME			= ../../zappy_graphic
LAUNCHER	= launcher.sh


RM				= rm -rf
MKDIR     = mkdir -p

CXXFLAGS	= -W -Wall -Wextra -std=c++11

INCFLAGS	= -I../../include/graphic
INCFLAGS	+= -I../../include/lib

LIBFLAGS	= -L../lib

SFMLFLAGS	= -lsfml-system -lsfml-window -lsfml-audio -lsfml-graphics
SYSFLAGS	= -ldl -lrt -lxcb -lpthread

##
## Sources
##
INC_PATH	=	../../include/graphic
SRC				=	Main.cpp
INC				= System.hh

CORE_PATH     = core
CORE_SRC      = Client.cpp \
								Interpreter.cpp \
								GameCore.cpp \
								GameEngine.cpp \
								InputManager.cpp \
								MapManager.cpp \
								AObjModule.cpp
CORE_INC      = $(CORE_SRC:%.cpp=%.hh)

ENGINE_PATH		=	engine
ENGINE_SRC	  = GraphicCore.cpp \
								GraphicEngine.cpp \
								ARenderer.cpp \
								RendererEnv.cpp \
								RendererInterface.cpp \
								RendererObject.cpp \
								Camera.cpp
ENGINE_INC	  =	$(GRAPHIC_SRC:%.cpp=%.hh)

OBJECT_PATH		=	object
OBJECT_SRC		=	AObject.cpp \
								AObjEnv.cpp \
								AObjEffect.cpp \
								AObjItem.cpp \
								AObjItemStone.cpp \
								AObjPlayer.cpp
OBJECT_INC  	= $(ENTITIES_SRC:%.cpp=%.hh)

OBJENV_PATH 	= object/env
OBJENV_SRC  	= Floor.cpp \
								Ground.cpp
OBJENV_INC  	= $(OBJENV_SRC:%.cpp=%.hh)

OBJEFFECT_PATH 	= object/effect
OBJEFFECT_SRC  	=	Cloud.cpp
OBJEFFECT_INC  	= $(OBJEFFECT_SRC:%.cpp=%.hh)

OBJITEM_PATH 	= object/item
OBJITEM_SRC  	= Food.cpp \
								StoneLinemate.cpp \
								StoneDeraumere.cpp \
								StoneSibur.cpp \
								StoneMendian.cpp \
								StonePhiras.cpp \
								StoneThystame.cpp

OBJITEM_INC  	= $(OBJITEM_SRC:%.cpp=%.hh)

OBJPLAYER_PATH 	= object/player
OBJPLAYER_SRC  	= Egg.cpp \
									Player.cpp
OBJPLAYER_INC  	= $(OBJPLAYER_SRC:%.cpp=%.hh)


SYS_PATH	    =	system
SYS_SRC		    =	Exception.cpp \
								FileSerializer.cpp \
								RessourceManager.cpp \
								AFileVarsManager.cpp \
								ConfigManager.cpp \
								CordManager.cpp \
								ScoreManager.cpp \
								CordRect.cpp
SYS_INC		    = $(SYS_SRC:%.cpp=%.hh)

##
## Dependencies
##
DEP							= $(patsubst %,$(INC_PATH)/%,$(INC))
CORE_DEP				=	$(patsubst %,$(INC_PATH)/$(CORE_PATH)/%,$(CORE_INC))
ENGINE_DEP			=	$(patsubst %,$(INC_PATH)/$(ENGINE_PATH)/%,$(ENGINE_INC))
OBJECT_DEP			=	$(patsubst %,$(INC_PATH)/$(OBJECT_PATH)/%,$(OBJECT_INC))
OBJENV_DEP			=	$(patsubst %,$(INC_PATH)/$(OBJENV_PATH)/%,$(OBJENV_INC))
OBJEFFECT_DEP		=	$(patsubst %,$(INC_PATH)/$(OBJEFFECT_PATH)/%,$(OBJEFFECT_INC))
OBJITEM_DEP			=	$(patsubst %,$(INC_PATH)/$(OBJITEM_PATH)/%,$(OBJITEM_INC))
OBJPLAYER_DEP		=	$(patsubst %,$(INC_PATH)/$(OBJPLAYER_PATH)/%,$(OBJPLAYER_INC))
SYS_DEP					=	$(patsubst %,$(INC_PATH)/$(SYS_PATH)/%,$(SYS_INC))


##
## Objetcs
##
OBJ_PATH	= ../../obj
OBJ		    = $(SRC:%.cpp=$(OBJ_PATH)/%.o) \
						$(CORE_SRC:%.cpp=$(OBJ_PATH)/$(CORE_PATH)/%.o) \
						$(ENGINE_SRC:%.cpp=$(OBJ_PATH)/$(ENGINE_PATH)/%.o) \
						$(OBJECT_SRC:%.cpp=$(OBJ_PATH)/$(OBJECT_PATH)/%.o) \
						$(OBJENV_SRC:%.cpp=$(OBJ_PATH)/$(OBJENV_PATH)/%.o) \
						$(OBJEFFECT_SRC:%.cpp=$(OBJ_PATH)/$(OBJEFFECT_PATH)/%.o) \
						$(OBJITEM_SRC:%.cpp=$(OBJ_PATH)/$(OBJITEM_PATH)/%.o) \
						$(OBJPLAYER_SRC:%.cpp=$(OBJ_PATH)/$(OBJPLAYER_PATH)/%.o) \
						$(SYS_SRC:%.cpp=$(OBJ_PATH)/$(SYS_PATH)/%.o)

$(OBJ_PATH)/%.o: %.cpp $(DEP)
	@$(MKDIR) $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ_PATH)/$(CORE_PATH)/%.o: $(CORE_PATH)/%.cpp  $(CORE_DEP)
	@$(MKDIR) $(OBJ_PATH)/$(CORE_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ_PATH)/$(ENGINE_PATH)/%.o: $(ENGINE_PATH)/%.cpp  $(ENGINE_DEP)
	@$(MKDIR) $(OBJ_PATH)/$(ENGINE_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ_PATH)/$(OBJECT_PATH)/%.o: $(OBJECT_PATH)/%.cpp  $(OBJECT_DEP)
	@$(MKDIR) $(OBJ_PATH)/$(OBJECT_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ_PATH)/$(OBJENV_PATH)/%.o: $(OBJENV_PATH)/%.cpp  $(OBJENV_DEP)
	@$(MKDIR) $(OBJ_PATH)/$(OBJENV_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ_PATH)/$(OBJEFFECT_PATH)/%.o: $(OBJEFFECT_PATH)/%.cpp  $(OBJEFFECT_DEP)
	@$(MKDIR) $(OBJ_PATH)/$(OBJEFFECT_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ_PATH)/$(OBJITEM_PATH)/%.o: $(OBJITEM_PATH)/%.cpp  $(OBJITEM_DEP)
	@$(MKDIR) $(OBJ_PATH)/$(OBJITEM_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ_PATH)/$(OBJPLAYER_PATH)/%.o: $(OBJPLAYER_PATH)/%.cpp  $(OBJPLAYER_DEP)
	@$(MKDIR) $(OBJ_PATH)/$(OBJPLAYER_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ_PATH)/$(SYS_PATH)/%.o: $(SYS_PATH)/%.cpp  $(SYS_DEP)
	@$(MKDIR) $(OBJ_PATH)/$(SYS_PATH)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

##
## Rules
##
$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(INCFLAGS) $(LIBFLAGS) $(SFMLFLAGS) $(SYSFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME) $(LAUNCHER)

re: fclean all

.PHONY: re fclean clean all
