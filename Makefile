COMPILER = g++
SOURCES = main.cpp student.cpp field.h field_typed.h field_format.h object_stream_reader.h table_printer.h
EXEC_FILENAME = prog.exe

all: compile
run: compile
	@./${EXEC_FILENAME}
compile:
	${COMPILER} ${SOURCES} -o ${EXEC_FILENAME} -w
clear:
	rm -f *.o ${EXEC_FILENAME}

