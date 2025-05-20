CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -Iinclude

SRC = src/Book.cpp \
      src/Magazine.cpp \
      src/User.cpp \
      src/LibrarySystem.cpp \
      src/LibraryException.cpp

TARGET = library_system
MAIN = main.cpp

all: $(TARGET)

$(TARGET): $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(SRC) $(MAIN)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o logs/transactions.txt
