CC=gcc
OUT=main
START=main.o
TESTS=$(notdir $(basename $(wildcard tst/*.c)))
TEST_OBJS=$(addsuffix .t.o, $(TESTS))
TEST_OUTS=$(addsuffix .test, $(TESTS))
MODES=$(addsuffix .o, $(notdir $(wildcard src/modes/*.c)))
OBJS=io.o log.o util.o engine.o $(MODES)
C_FLAGS=-I . -std=c11
LINKER_FLAGS=-lSDL2 -lSDL2_image

all: $(OUT) $(TESTS)

tests: $(TEST_OUTS)

$(OUT): $(OBJS) $(START)
	$(CC) $(OBJS) $(START) $(LINKER_FLAGS) -o $(OUT) $(C_FLAGS)

%.test: %.t.o $(OBJS)
	$(CC) $(OBJS) $< $(LINKER_FLAGS) -o $@ $(C_FLAGS)

%.t.o: tst/%.c
	$(CC) -c -o $@ $< $(C_FLAGS)

%.c.o: src/modes/%.c
	$(CC) -c -o $@ $< $(C_FLAGS)

%.o: src/%.c
	$(CC) -c -o $@ $< $(C_FLAGS)

clean:
	rm -f *.o
	rm -f $(OUT)
