G++ = g++
FILES = main.cpp
EXE = Vector
DEL = rm

all:
	$(G++) $(FILES) -o $(EXE)

del:
	$(DEL) -r $(EXE)