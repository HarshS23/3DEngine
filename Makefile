# # Target: prereqs/dependices 
# # 	commands

CC = gcc
CFLAGS = -Wall -Wextra -I/opt/homebrew/include/SDL2
LDFLAGS = -L/opt/homebrew/lib -lSDL2 -lm
SRC_DIR = src
EXECUTE = bin
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJFILES = $(patsubst $(SRC_DIR)/%.c, $(EXECUTE)/%.o, $(SRC_FILES))
TARGET = $(EXECUTE)/3DRenderer

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(TARGET) $(LDFLAGS)

$(EXECUTE)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/%.h
	mkdir -p $(EXECUTE)
	$(CC) $(CFLAGS) -c $< -o $@

build: all
	rm -f $(OBJFILES)
	./$(TARGET)

clean:
	rm -rf $(EXECUTE)/*