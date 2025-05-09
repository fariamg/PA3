# Ferramentas e flags
CXX      := g++
CXXFLAGS := -std=c++11 -Iinclude -Wall -Wextra -g

# Diretórios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Executável
TARGET := $(BIN_DIR)/pa3.out

# Fontes e objetos
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean

all: dirs $(TARGET)

# cria os diretórios bin/ e obj/
dirs:
	mkdir -p $(BIN_DIR) $(OBJ_DIR)

# linkagem
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# compilação de cada fonte em objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)