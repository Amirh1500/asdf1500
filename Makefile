CXX = g++
CXXFLAGS = -std=c++20
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SOURCES = main.cpp Object.cpp Moveable.cpp Zombies.cpp Sun.cpp Bullets.cpp Static.cpp Sunflowers.cpp Potatos.cpp Greenplants.cpp Background.cpp
HEADERS = Object.hpp Moveable.hpp Zombies.hpp Sun.hpp Bullets.hpp Static.hpp Sunflowers.hpp Potatos.hpp Greenplants.hpp Background.hpp global.hpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = pvz.out

all: $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(TARGET)