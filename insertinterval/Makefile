CC=rustc
OBJ=main.o
OUT=main
DEBUGFLAGS=-g
SRC=main.rs

build:
		$(CC) $(SRC)

debugbuild: 
		$(CC) $(SRC) $(DEBUGFLAGS)

.PHONY: clean

clean:
		rm -f $(OUT)


