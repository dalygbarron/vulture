CC=gcc
OUT=main
START=main.o
OBJS=io.o log.o util.o
C_FLAGS=-I . -std=c11
LINKER_FLAGS=-lSDL2 -lSDL2_image

all: $(OUT)

$(OUT): $(OBJS) $(START)
	$(CC) $(OBJS) $(START) $(LINKER_FLAGS) -o $(OUT) $(C_FLAGS)

%.o: src/%.c
	$(CC) -c -o $@ $< $(C_FLAGS)
