# Define the compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define the libraries to link
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Define the source and object files
SRCS = main.cpp grid.cpp
OBJS = $(SRCS:.cpp=.o)

# Define the target executable
TARGET = main

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

