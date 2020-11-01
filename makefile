SDIR =src
ODIR =obj
IDIR =include

CC=gcc
CFLAGS=-I $(IDIR) -Wall -g

LIBS=-lm

SRC = $(wildcard $(SDIR)/*.c)
DEPS = $(wildcard $(IDIR)/*.h)
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

# $(info $$OBJ is [${OBJ}])

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


.PHONY: clean
clean:
	rm -f $(ODIR)/*.o 
	rm main