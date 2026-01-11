CC = cc
CFLAGS = -Wall -Wextra -pedantic -std=11 -g

SRC_DIR = src
BIN_DIR = bin
INC_DIRS = include /usr/local/include
LIB_DIRS = lib /usr/local/lib

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:.c=.o)
PROGS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRCS))

INC_FLAGS := $(addprefix -I, $(INC_DIRS))
LIB_FLAGS := $(addprefix -L, $(LIB_DIRS))

## хз как нафиг и зачем но продолжи, потом поймешь зачем оно
