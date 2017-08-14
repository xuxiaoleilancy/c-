
CC = gcc
XX = g++
CFLAGS = -Wall -O -g

SOURCES = $(wildcard *.c *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))

$(TARGET):$(OBJS)
	$(XX) $(OBJS) -o $(TARGET)
	chmod a+x $(TARGET)

clean:
	rm -rf *.o $(TARGET)