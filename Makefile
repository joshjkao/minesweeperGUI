SRC_DIR = src
BUILD_DIR = build/debug
CC=g++
CCFLAGS=-g -Wall -std=c++11
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
INCLUDE_PATHS = -I include 
LIBRARY_PATHS = -L lib
LINKER_FLAGS = -lSDL2 -lSDL2_image

all:
	$(CC) $(CCFLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) 

clean:
	rm -f *.o ./build/debug/play