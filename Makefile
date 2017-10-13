CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o caratsuba.o armstrong.o perfect.o morze.o transfer.o

LIBS =

TARGET =	hardLab.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	
	g++ src/cpp/*.cpp -I src/includes/ -o hardLab

clean:
	rm -f $(OBJS) $(TARGET)
