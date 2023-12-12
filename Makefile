CC = gcc
CFLAGS = -Wall

all: testeh testec

testeh: *.h
    $(CC) $(CFLAGS) *.h -o testeh

testec: *.c
    $(CC) $(CFLAGS) *.c -o testec

clean:
    rm -f testeh testec