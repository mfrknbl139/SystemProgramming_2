CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =
SRCDIR = src
INCDIR = include
BINDIR = bin

all: $(BINDIR)/program

$(BINDIR)/program: $(BINDIR)/main.o $(BINDIR)/chain_healing.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BINDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/chain_healing.h
	mkdir $(BINDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(BINDIR)/chain_healing.o: $(SRCDIR)/chain_healing.c $(INCDIR)/chain_healing.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(BINDIR)/*.o $(BINDIR)/program
