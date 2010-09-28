SRC      := src/*.c
COMPILER := clang
CFLAGS   := 
IFLAGS   := -Iinclude/
LFLAGS   := -lpthread -lGL -lGLU
EFLAGS   := -Wall -Wextra

all: $(SRC)
	$(COMPILER) -o$@ $(CFLAGS) $(IFLAGS) $(LFLAGS) $(EFLAGS) $(SRC)
