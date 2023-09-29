TARGET = ExercicioFilmes
CC = g++
LD = g++
WARN = -Wall -std=c++11
OBJS = main.cpp catalogo.cpp

all: $(OBJS)
	$(LD) $(WARN) -o $(TARGET) $(OBJS)