TARGET = Slist
OBJS = listcl.o list.o

all: $(TARGET)

$(TARGET): $(OBJS) 
	g++  $(OBJS) -o $(TARGET)

listcl.o: listcl.cpp listcl.h
	g++ -c listcl.cpp

list.o: list.cpp listcl.h
	g++ -c list.cpp

clean:
	rm *.o