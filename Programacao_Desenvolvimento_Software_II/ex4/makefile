# Variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++17
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
TARGET = vpl_execution

# Lista de objetos
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/list.o

# Regra padrão
all: $(TARGET)

# Compilação do executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar main.o
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/list.hpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regra para compilar list.o
$(BUILD_DIR)/list.o: $(SRC_DIR)/list.cpp $(INCLUDE_DIR)/list.hpp $(INCLUDE_DIR)/node.hpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean