TARGET = Generator
OBJS = Generator.o database_main.o Database.o Parsing.o

all: $(TARGET)

$(TARGET): $(OBJS) 
	g++  $(OBJS) -o $(TARGET)

Generator.o: Generator.cpp DataBase.h Generator.h fStudent.h
	g++ -c Generator.cpp

database_main.o: database_main.cpp DataBase.h Generator.h fStudent.h
	g++ -c database_main.cpp

Database.o: Database.cpp DataBase.h Generator.h fStudent.h
	g++ -c Database.cpp

Parsing.o: Parsing.cpp DataBase.h Generator.h fStudent.h
	g++ -c Parsing.cpp

clean:
	rm *.o