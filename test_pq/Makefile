CXX = g++
# google test home directory
GTEST_DIR = /home/mitshan/programming/cpp/googletest/googletest
SRCS = pq_gtest.cc
EXEC = pq_gtest
CPPFLAGS = -isystem $(GTEST_DIR)/include
CXXFLAGS = -std=c++11
LDLIBS = -lgtest
LDFLAGS = -pthread

all : $(EXEC)

pq_gtest.o : pq_gtest.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRCS)

$(EXEC) : pq_gtest.o
	$(CXX) -o $(EXEC) $(LDFLAGS) pq_gtest.o $(LDLIBS)

clean :
	rm -f $(EXEC) *.o *~
