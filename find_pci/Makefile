CXX=g++
CXXFLAGS=-std=c++11 -lpci
TARGET=find_pci.test

$(TARGET):main.cpp
	$(CXX) $< $(CXXFLAGS) -o $@

clean:
	rm -f $(TARGET)
