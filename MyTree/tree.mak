TARGET = MyTree
OBJS = Tree.o tree_main.o

all: $(TARGET)

$(TARGET): $(OBJS) 
	g++  $(OBJS) -o $(TARGET)

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp

tree_main.o: tree_main.cpp Tree.h
	g++ -c tree_main.cpp

clean:
	rm *.o