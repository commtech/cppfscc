SHELL = /bin/sh
TARGET = libcppfscc.so

SRCS = $(shell echo src/*.cpp)
HEADERS = $(shell echo src/*.hpp)
OBJS = $(SRCS:.cpp=.o)
INC = libs/cfscc/src/

CXXFLAGS = -fPIC -Wall -Wextra -std=c++0x -I $(INC)
LDFLAGS = -shared

CC = g++

all: $(TARGET)

$(TARGET): $(HEADERS) $(OBJS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(HEADERS) $(OBJS) -o $(TARGET) -lm

clean:
	rm src/*.o
	rm *.so
