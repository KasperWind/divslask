#C_FLAGS := -g -Wall -Iinclude -D DEBUG
C_FLAGS := -g -Wall -Iinclude
CC := gcc
RM := rm
LINKFLAGS :=

.PHONY: $(TARGET)
.PHONY: clean

VPATH:= ./src/ ./obj/ ./include/

# Path for .c , .h and .o Files 
SRC_PATH := ./src/
OBJ_PATH := ./obj/
INC_PATH := -I ./include

# Executable Name 
TARGET := bin/List

# Files to compile
OBJ1 := List.o \
	main.o

OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo [CC] $<
	@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)                  

# Build final Binary
$(TARGET): $(OBJ)
	@echo [INFO] Creating Binary Executable [$(TARGET)]
	@$(CC) -o $@ $^ $(LINKFLAGS)

# Clean all the object files and the binary
clean:
	@echo "[Cleaning]"
	@$(RM) -rfv $(OBJ_PATH)*
	@$(RM) -rfv $(TARGET)
