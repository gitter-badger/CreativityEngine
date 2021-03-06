#OBJS specifies which files to compile as part of the project
OBJS = src/engine/*.cpp

#CC specifies which compiler we're using
UNAME := $(shell uname)

ifeq ($(OS),Windows_NT)
    CC = g++
else
	ifeq ($(UNAME),Darwin)
	CC = g++
	else
	CC = g++-5
	endif
endif

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -O3 -std=c++14

#LINKER_FLAGS specifies the libraries we're linking against

ifeq ($(UNAME),Darwin) # Running on macOS
LINKER_FLAGS = -I./include -I./external/glm -lSDL2 -framework GLUT -framework OpenGL -framework Cocoa 
else # Running on Windows or Linux (Windows not tested, linux compiles)
LINKER_FLAGS = -I./include -I./external/glm -lSDL2 -lGL -lGLU -lm -lglut 
endif
#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin/creativity

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm -rf bin/ *.log