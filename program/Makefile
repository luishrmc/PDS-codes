CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=program

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

all:vpl_execution

#objects
${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Funcionario.o ${BUILD_DIR}/Pessoa.o ${BUILD_DIR}/Professor.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

#compile
${BUILD_DIR}/Funcionario.o: ${INCLUDE_DIR}/Funcionario.hpp ${SRC_DIR}/entidades/Funcionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Funcionario.cpp -o ${BUILD_DIR}/Funcionario.o

${BUILD_DIR}/Pessoa.o: ${INCLUDE_DIR}/Pessoa.hpp ${SRC_DIR}/entidades/Pessoa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Pessoa.cpp -o ${BUILD_DIR}/Pessoa.o

${BUILD_DIR}/Professor.o: ${INCLUDE_DIR}/Professor.hpp ${SRC_DIR}/entidades/Professor.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/entidades/Professor.cpp -o ${BUILD_DIR}/Professor.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Funcionario.hpp ${INCLUDE_DIR}/Pessoa.hpp ${INCLUDE_DIR}/Professor.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

#link
vpl_execution: ${BUILD_DIR}/Funcionario.o ${BUILD_DIR}/Pessoa.o ${BUILD_DIR}/Professor.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o vpl_execution ${BUILD_DIR}/Funcionario.o ${BUILD_DIR}/Pessoa.o ${BUILD_DIR}/Professor.o ${BUILD_DIR}/main.o

clean:
	rm -f ${BUILD_DIR}/*
