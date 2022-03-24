CPPFLAGS = -std=c++11


SRC_DIR    := src
HEADER_DIR := include
BIN_DIR    := bin
OBJ_DIR 	:= $(BIN_DIR)/obj

EXECUTABLE := $(BIN_DIR)/main

OBJECTS = $(addprefix $(OBJ_DIR)/,main.o admin.o number.o SHA256.o signatures.o user.o)


all: directories $(EXECUTABLE)

directories:
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE): $(OBJECTS)
	g++ -o $@ $(CPPFLAGS) $(OBJECTS) 
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@ -I $(HEADER_DIR)

clean: 
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)