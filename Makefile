CXXFLAGS += -std=c++11

main : use_pq.o
	$(CXX) use_pq.o -o main

use_pq.o : priority_queue.h use_pq.cc
	$(CXX) $(CXXFLAGS) -c use_pq.cc

clean :
	rm -f *~ main *.o


