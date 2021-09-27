COMPILER = g++
SOURCES = main.cpp object_stream_reader.h student_table_printer.cpp student.cpp
EXEC_FILENAME = prog

all: compile
run: compile
	@./${EXEC_FILENAME}
compile:
	${COMPILER} ${SOURCES} -o ${EXEC_FILENAME} -w
clear:
	rm -f *.o ${EXEC_FILENAME}

