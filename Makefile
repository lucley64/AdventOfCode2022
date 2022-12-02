CC = /usr/bin/g++
LNK = 

srcdir = ./src/
bindir = ./bin/

PROG = $(bindir)a.out
SRC = $(wildcard $(srcdir)*.cpp)
HEAD = $(wildcard $(srcdir)*.h)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.cpp=.o))

all: clean build

.PHONY: launch build clean


launch: 
	$(PROG)

build: $(PROG)

$(PROG) : $(OBJ)
	$(CC) $^ -o $@ $(LNK)

$(bindir)%.o : $(srcdir)%.cpp
	$(CC) -c $^ -o $@

clean: 
	rm $(PROG) $(OBJ)