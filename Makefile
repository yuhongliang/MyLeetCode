CXXFLAGS=-Wall -g -std=c++0x
CCC=g++
TARGET=LRU_Cache Reorder_List  Sort_list word_break

all:$(TARGET)

.cpp.o:

clean:
	rm $(TARGET) ./*~ *.o -f
