CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BINARIES  := binar
SRC       := src
INCLUDE   := include

LIBRARIES   := 
EXECUTABLE  := main


all: $(BINARIES)/$(EXECUTABLE)

run: clean all
	clear
	./$(BINARIES)/$(EXECUTABLE)

$(BINARIES)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BINARIES)/*