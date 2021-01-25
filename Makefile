CC=gcc
LIBS=$(shell pkg-config --libs sdl2)
CFLAGS=$(shell pkg-config --cflags sdl2)
SRCS=$(wildcard *.cpp);
OBJS=$(SRCS:.cpp=o)

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

NASU: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

run:
	./NASU
	
clean:
	rm -f *.o
	rm -f NASU
