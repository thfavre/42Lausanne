CC = g++
CFLAGS = -std=c++11 -DGLEW_STATIC #-Wall
LDFLAGS = -lglfw -lGLEW -lGL -ldl

SRC = src/Application.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = My3DProject

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
