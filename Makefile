# Project name
NAME = Freeze

# Directory structure
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
LIB_DIR = lib

# External libraries directories
GLFW_DIR = $(LIB_DIR)/glfw
GLAD_DIR = $(LIB_DIR)/glad

# Include paths for libraries
LIB_INCLUDES = -I$(GLFW_DIR)/include -I$(GLAD_DIR)/include

# Source files and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(GLAD_DIR)/src/glad.c
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
OBJS += $(BUILD_DIR)/glad.o # Add glad.o separately for convenience

# Static library to build
STATIC = $(BUILD_DIR)/lib$(NAME).a

# Compiler and archiver
CXX = g++
AR = ar

# Compiler flags
WARN_FLAGS = -Wall -Wextra
CXXSTD = -std=c++17
GRAPHICS_FLAGS = -lGL -lglfw -ldl
CXXFLAGS = $(WARN_FLAGS) $(CXXSTD) -I$(INCLUDE_DIR) $(LIB_INCLUDES)

# Phony targets
.PHONY: all clean

# Default target to build the static library
all: $(STATIC)

# Rule to create the static library
$(STATIC): $(OBJS) | $(BUILD_DIR)
	$(AR) rcs $@ $^

# Rule to compile C++ source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile glad C source file separately
$(BUILD_DIR)/glad.o: $(GLAD_DIR)/src/glad.c | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $@

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)
