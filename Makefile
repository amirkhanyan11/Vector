G++ = g++
FILES = main.cpp vector_object_file.o
EXE = Vector
DEL = rm

all:
	$(G++) $(FILES) -o $(EXE)

del:
	$(DEL) -r $(EXE)