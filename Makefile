CC=gcc
OUT=main
START=main.o
MODES=$(addsuffix .o, $(notdir $(wildcard src/modes/*.c)))
OBJS=io.o log.o util.o engine.o $(MODES)
C_FLAGS=-I . -std=c11
LINKER_FLAGS=-lSDL2 -lSDL2_image

all: $(OUT)

$(OUT): $(OBJS) $(START)
	$(CC) $(OBJS) $(START) $(LINKER_FLAGS) -o $(OUT) $(C_FLAGS)

%.c.o: src/modes/%.c
	$(CC) -c -o $@ $< $(C_FLAGS)

%.o: src/%.c
	$(CC) -c -o $@ $< $(C_FLAGS)

clean:
	rm -f *.o
	rm -f $(OUT)
