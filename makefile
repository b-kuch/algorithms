SDIR =src
ODIR =obj
LDIR =lib
IDIR =include

CC=gcc
CFLAGS=-I $(IDIR)

LIBS=-lm


DEPS = $(wildcard $(IDIR)/*.h)
OBJ = $(wildcard $(ODIR)/*.o)
SRC = $(wildcard $(SDIR)/*.c)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 