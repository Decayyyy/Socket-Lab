SRC_DIR := src
OBJ_DIR := obj
# all src files
SRC := $(wildcard $(SRC_DIR)/*.c)
# all objects
OBJ := $(OBJ_DIR)/y.tab.o $(OBJ_DIR)/lex.yy.o $(OBJ_DIR)/parse.o $(OBJ_DIR)/example.o
OBJ2 := $(OBJ_DIR)/liso_server.o $(OBJ_DIR)/parse.o $(OBJ_DIR)/y.tab.o $(OBJ_DIR)/lex.yy.o  $(OBJ_DIR)/utils.o $(OBJ_DIR)/msg_response.o $(OBJ_DIR)/log.o $(OBJ_DIR)/cgi.o


# all binaries
BIN := example liso_server liso_client
# C compiler
CC  := gcc
# C PreProcessor Flag
CPPFLAGS := -Iinclude
# compiler flags
CFLAGS   := -g -Wall
# DEPS = parse.h y.tab.hsendRet

default: all
all : liso_server echo_client



$(SRC_DIR)/lex.yy.c: $(SRC_DIR)/lexer.l
	flex -o $@ $^

$(SRC_DIR)/y.tab.c: $(SRC_DIR)/parser.y
	yacc -d $^
	mv y.tab.c $@
	mv y.tab.h $(SRC_DIR)/y.tab.h

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

liso_server: $(OBJ2)
	$(CC) -Werror $^ -o $@
echo_client: $(OBJ_DIR)/liso_client.o
	$(CC) -Werror $^ -o $@

$(OBJ_DIR):
	mkdir $@

clean:
	$(RM) $(OBJ) $(BIN) $(SRC_DIR)/lex.yy.c $(SRC_DIR)/y.tab.*
	$(RM) -r $(OBJ_DIR)
