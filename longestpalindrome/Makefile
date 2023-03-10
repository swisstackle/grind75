CC=gcc
OBJ=main.o
OUT=main
DEBUGFLAGS=-g
SRC=main.c
#IN = include
#CFLAGS=-I$(IN)
#DEPS=
LIBS=-lm


#%.o: %.c $(DEPS)
     #%(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o $(OUT) $^ $(CFLAGS)

debugbuild: 
	$(CC) -o $(OUT) $(SRC) $(DEBUGFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(OUT)
	rm -f $(OBJ)


