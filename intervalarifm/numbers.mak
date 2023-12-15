TARGET = number
OBJS = Numbers.o clnum.o

all: $(TARGET)

$(TARGET): $(OBJS) 
	g++  $(OBJS) -o $(TARGET)

listcl.o: Numbers.cpp clnum.h
	g++ -c Numbers.cpp

list.o: clnum.cpp clnum.h
	g++ -c clnum.cpp

clean:
	rm *.o