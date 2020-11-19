.DELETE_ON_ERROR:
# main files
SDIR =src
ODIR =obj
IDIR =include

SRC = $(wildcard $(SDIR)/*.c) $(wildcard $(SDIR)/sorting_algorithms/*.c) 
DEPS = $(wildcard $(IDIR)/*.h) $(wildcard $(IDIR)/sorting_algorithms/*.h) 
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

CC=gcc
CFLAGS=-I$(IDIR) -Wall -ggdb -Og

LIBS=-lm

# $(info $$OBJ is [${OBJ}])

main.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

#$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

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
