CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS= -L/usr/local/lib -lsodium # libsodium
SRCDIR = src
BINDIR = target
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BINDIR)/%.o)
EXEC = $(BINDIR)/main

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS) 

$(BINDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rfv $(BINDIR)
