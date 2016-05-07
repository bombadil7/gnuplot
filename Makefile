CC = gcc
FLAGS = -Wall -O2 -g
OBJS = gpFromFile.o

.PHONY: all clean run

all: ${OBJS}
	@echo "Building.."
	${CC} ${FLAGS} ${OBJS} -o target_bin -lm

%.o: %.c
	@echo "Compiling.."
	${CC} ${FLAGS} -c $*.c

clean:
	@echo "Deleting " $(shell ls target_bin) $(shell ls *.o)
	-rm -rf *.o
	-rm -f target_bin

run:
	./target_bin

clean_dat:
	@echo "Removing data files: $(shell ls *.dat)"
	-rm -rf *.dat
