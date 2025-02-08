# Target: prereqs/dependices 
# 	commands
# gcc -o obj_parser main.c -lm -L/opt/homebrew/lib -I/opt/homebrew/include -lSDL2


# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -lm -L/opt/homebrew/lib -I/opt/homebrew/include -lSDL2

# Source and Object Files
SRC = main.c
OBJ = $(SRC:.c=.o)

# Output Executable
EXECUTABLE = obj_parser

# Default Build Target
all: $(EXECUTABLE)

# Rule to Compile Executable
$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) -o $(EXECUTABLE) $(CFLAGS)

# Rule to Compile Object Files
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean up Object Files and Executable
clean:
	rm -f $(OBJ) $(EXECUTABLE)
