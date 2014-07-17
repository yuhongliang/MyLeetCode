CXXFLAGS=-Wall -g -std=c++0x
CCC=g++
TARGET=LRU_Cache Reorder_List Sort_list word_break copy_list_with_random_pointer
TARGET+=single_number_2 add_two_numbers reverse_linked_list_2 partition_list
TARGET+=remove_duplicates_from_sorted_list remove_duplicates_from_sorted_list_2
TARGET+=rotate_list Remove_Nth swapPairs reverseKGroup

all:$(TARGET)

.cpp.o:

clean:
	rm $(TARGET) ./*~ *.o -f
