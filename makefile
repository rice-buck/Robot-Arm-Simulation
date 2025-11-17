CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/Cellar/sfml/3.0.2/include
LDFLAGS = -L/opt/homebrew/Cellar/sfml/3.0.2/lib \
          -lsfml-graphics -lsfml-window -lsfml-system

SRC = robotArmMatrix.cpp Matrix.cpp Vector.cpp
OUT = app

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) $(LDFLAGS) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
