CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o caratsuba.o armstrong.o perfect.o morze.o transfer.o rules.o bracket.o neighbors.o smoothing.o min.o magic.o

LIBS =

TARGET =	hardLab.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	
	g++ hyphenator/hyphenator.cpp src/cpp/*.cpp -I src/includes/ -I hyphenator/ -o hardLab

transfer:
	g++ -c src/cpp/transfer.cpp -I src/includes -I hyphenator/

clean:
	rm -f $(OBJS) $(TARGET)
