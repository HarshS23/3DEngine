# Target: prereqs/dependices 
# 	commands

CC = gcc
CFLAGS = -Wall -Wextra -I/opt/homebrew/include/SDL2
LDFLAGS = -L/opt/homebrew/lib -lSDL2 -lm
SRC_DIR = src
OBJ_DIR = bin
OBJFILES = $(OBJ_DIR)/main.o $(OBJ_DIR)/vector.o $(OBJ_DIR)/upng.o
TARGET = $(OBJ_DIR)/obj_parser

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/main.h $(SRC_DIR)/vector.h $(SRC_DIR)/upng.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/vector.o: $(SRC_DIR)/vector.c $(SRC_DIR)/vector.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/vector.c -o $(OBJ_DIR)/vector.o

$(OBJ_DIR)/upng.o: $(SRC_DIR)/upng.c $(SRC_DIR)/upng.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/upng.c -o $(OBJ_DIR)/upng.o

build: all
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR)/*
