RM = rm -rf 

# Compilador
CC=g++ 

LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test
 
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all clean doxy debug doc 


all: init questao1 questao2

debug: CFLAGS += -g -O0
debug: all

init:
	@mkdir -p $(OBJ_DIR)/questao1
	@mkdir -p $(OBJ_DIR)/questao2
	@mkdir -p $(BIN_DIR)

questao1: CFLAGS+= -I$(INC_DIR)/questao1
questao1: $(OBJ_DIR)/questao1/data.o $(OBJ_DIR)/questao1/funcionario.o $(OBJ_DIR)/questao1/empresa.o $(OBJ_DIR)/questao1/main.o  
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'questao1' criado em $(BIN_DIR)] +++"
	@echo "============="
$(OBJ_DIR)/questao1/data.o: $(SRC_DIR)/questao1/data.cpp $(INC_DIR)/questao1/data.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao1/funcionario.o: $(SRC_DIR)/questao1/funcionario.cpp $(INC_DIR)/questao1/funcionario.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao1/empresa.o: $(SRC_DIR)/questao1/empresa.cpp $(INC_DIR)/questao1/empresa.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao1/main.o: $(SRC_DIR)/questao1/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<


questao2: CFLAGS+= -I$(INC_DIR)/questao2
questao2: $(OBJ_DIR)/questao2/dado.o $(OBJ_DIR)/questao2/jogador.o $(OBJ_DIR)/questao2/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'questao2' criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/questao2/dado.o: $(SRC_DIR)/questao2/dado.cpp $(INC_DIR)/questao2/dado.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao2/jogador.o: $(SRC_DIR)/questao2/jogador.cpp $(INC_DIR)/questao2/jogador.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao2/main.o: $(SRC_DIR)/questao2/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*