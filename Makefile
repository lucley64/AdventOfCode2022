CC = /usr/bin/g++
LNK = 

srcdir = ./src/
bindir = ./bin/

PROG = $(bindir)a.out
SRC = $(wildcard $(srcdir)*.cpp)
HEAD = $(wildcard $(srcdir)*.h)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.cpp=.o))

all: $(PROG)

$(PROG) : $(OBJ)
	$(CC) $^ -o $@ $(LNK)

$(bindir)%.o : $(srcdir)%.cpp
	$(CC) -c $^ -o $@

.PHONY: launch


launch: 
	$(PROG)