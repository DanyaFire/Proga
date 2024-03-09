TARGET = Generator
OBJS = Generator.o database_main.o

all: $(TARGET)

$(TARGET): $(OBJS) 
	g++  $(OBJS) -o $(TARGET)

DataBase.o: Generator.cpp DataBase.h Generator.h
	g++ -c Generator.cpp

DataBase_main.o: database_main.cpp DataBase.h Generator.h
	g++ -c database_main.cpp

clean:
	rm *.o