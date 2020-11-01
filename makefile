SDIR =src
ODIR =obj
IDIR =include

CC=gcc
CFLAGS=-I$(IDIR) -Wall -g -Og

LIBS=-lm

SRC = $(wildcard $(SDIR)/*.c)
DEPS = $(wildcard $(IDIR)/*.h)
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

# $(info $$OBJ is [${OBJ}])

main.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


.PHONY: clean
clean:
	rm -f $(ODIR)/*.o 
	rm main.out

valgrind: main.out
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	--log-file=valgrind-out.txt \
	./main.out

debugger: main.out
	cp ./main.out ~/main.out
	gdb ~/main.out
