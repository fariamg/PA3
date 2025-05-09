# Ferramentas e flags
CXX      := g++
CXXFLAGS := -std=c++11 -Iinclude -Wall -Wextra -g

# Diretórios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Executável
TARGET := $(BIN_DIR)/pa3.out

# Fontes e objeto
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(BIN_DIR) $(OBJ_DIR) $(TARGET)

# Cria diretórios se não existirem
$(BIN_DIR):
    mkdir -p $(BIN_DIR)

$(OBJ_DIR):
    mkdir -p $(OBJ_DIR)

# Linkagem do executável
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) $^ -o $@

# Compilação de cada .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa binário e objetos
clean:
    rm -rf $(OBJ_DIR)/*.o $(TARGET)