CXX = g++
CXXFLAGS = -std=c++17 -O2

SRC = src/main.cpp src/Student.cpp src/Processor.cpp src/FileGenerator.cpp src/Timer.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = student-grades

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

