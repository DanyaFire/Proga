TARGET = poly
OBJS = polyg.o poly.o

all: $(TARGET)

$(TARGET): $(OBJS) 
	g++  $(OBJS) -o $(TARGET)

listcl.o: polyg.cpp polyg.h
	g++ -c poly.cpp

list.o: poly.cpp polyg.h
	g++ -c poly.cpp

clean:
	rm *.o