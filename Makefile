CXX = g++

INCLUDE_DIR = ./include
SRC_DIR = ./src
BIN_DIR = ./bin
TESTBIN_DIR = ./testbin
OBJ_DIR = ./obj

PROJ_OBJS = $(OBJ_DIR)/SixMensMorrisBoard.o
TEST_OBJ = $(OBJ_DIR)/testsixmensmorris.o
MAIN_OBJ = $(OBJ_DIR)/main.o

CXXFLAGS = -I $(INCLUDE_DIR) -Wall --std=c++14
TESTLDFLAGS = -lgtest -lgtest_main -lpthread

TEST_NAME = testsixmen 
PROJ_NAME = PROJ3

all: directories RUNTESTS $(BIN_DIR)/$(PROJ_NAME)

RUNTESTS: $(TESTBIN_DIR)/$(TEST_NAME)
	$(TESTBIN_DIR)/$(TEST_NAME)


$(BIN_DIR)/$(PROJ_NAME): $(PROJ_OBJS) $(MAIN_OBJ)
	$(CXX) $(MAIN_OBJ) $(PROJ_OBJS) -o $(BIN_DIR)/$(PROJ_NAME) $(CXXFLAGS) $(TESTLDFLAGS)


$(TESTBIN_DIR)/$(TEST_NAME): $(PROJ_OBJS) $(TEST_OBJ)
	$(CXX) $(PROJ_OBJS) $(TEST_OBJ) -o $(TESTBIN_DIR)/$(TEST_NAME) $(CXXFLAGS) $(TESTLDFLAGS)

$(OBJ_DIR)/SixMensMorrisBoard.o: $(SRC_DIR)/SixMensMorrisBoard.cpp $(INCLUDE_DIR)/SixMensMorrisBoard.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/SixMensMorrisBoard.cpp -c -o $(OBJ_DIR)/SixMensMorrisBoard.o

$(TEST_OBJ): $(SRC_DIR)/testsixmensmorris.cpp $(INCLUDE_DIR)/SixMensMorrisBoard.h
	$(CXX) $(SRC_DIR)/testsixmensmorris.cpp -c -o $(OBJ_DIR)/testsixmensmorris.o $(CXXFLAGS) 

$(MAIN_OBJ): $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/SixMensMorrisBoard.h
	$(CXX) $(SRC_DIR)/main.cpp -c -o $(OBJ_DIR)/main.o $(CXXFLAGS) 

directories:# $(BIN_DIR) $(TESTBIN_DIR) $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(TESTBIN_DIR)
	mkdir -p $(OBJ_DIR)
#$(BIN_DIR):
#	mkdir -p $(BIN_DIR)

#$(TESTBIN_DIR):
#	mkdir -p $(TESTBIN_DIR)

#$(OBJ_DIR):
#	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o 