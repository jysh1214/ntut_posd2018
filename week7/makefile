.PHONY: clean dirs

BIN=bin
SRC=src
TEST=test
OBJ=obj
LIBS=-lgtest -lpthread

all: dirs $(BIN)/hw7

$(BIN)/hw7: $(TEST)/ut_fs.cpp $(TEST)/ut_fs.h $(SRC)/node.h $(SRC)/folder.h $(SRC)/file.h $(SRC)/link.h  $(SRC)/node_iterator.h $(SRC)/node_builder.h $(OBJ)/find_visitor.o $(OBJ)/info_content_visitor.o $(OBJ)/find_link_visitor.o $(OBJ)/find_node_by_pathname_visitor.o
	g++ -g -std=c++11 $< $(OBJ)/find_visitor.o $(OBJ)/info_content_visitor.o $(OBJ)/find_link_visitor.o $(OBJ)/find_node_by_pathname_visitor.o -o $@ $(LIBS)

$(OBJ)/find_visitor.o: $(SRC)/find_visitor.cpp $(SRC)/find_visitor.h
	g++ -g -std=c++11 -c $< -o $@

$(OBJ)/info_content_visitor.o: $(SRC)/info_content_visitor.cpp $(SRC)/info_content_visitor.h
	g++ -g -std=c++11 -c $< -o $@

$(OBJ)/find_link_visitor.o: $(SRC)/find_link_visitor.cpp $(SRC)/find_link_visitor.h
	g++ -g -std=c++11 -c $< -o $@

$(OBJ)/find_node_by_pathname_visitor.o: $(SRC)/find_node_by_pathname_visitor.cpp $(SRC)/find_node_by_pathname_visitor.h
	g++ -g -std=c++11 -c $< -o $@

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)

stat:
	wc src/* test/*
