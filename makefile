# tomergal40@gmail.com
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
VALGRIND = valgrind --leak-check=full --error-exitcode=1

# Source files
SOURCES = graph.cpp queue.cpp priority_queue.cpp union_find.cpp algorithms.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Test files
GRAPH_TEST = graph_test.cpp
QUEUE_TEST = queue_test.cpp
PQ_TEST = priority_queue_test.cpp
UF_TEST = union_find_test.cpp
ALG_TEST = algorithms_test.cpp

# Demo file
MAIN_DEMO = main.cpp

# Create main demo program
Main: $(OBJECTS) $(MAIN_DEMO:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Create graph test program
GraphTest: graph.o $(GRAPH_TEST:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Create queue test program
QueueTest: queue.o $(QUEUE_TEST:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Create priority queue test program
PQTest: priority_queue.o $(PQ_TEST:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Create union find test program
UFTest: union_find.o $(UF_TEST:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Create algorithms test program
AlgTest: $(OBJECTS) $(ALG_TEST:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test all components
test: GraphTest QueueTest PQTest UFTest AlgTest
	@echo "Running Graph tests..."
	./GraphTest
	@echo "\nRunning Queue tests..."
	./QueueTest
	@echo "\nRunning Priority Queue tests..."
	./PQTest
	@echo "\nRunning Union Find tests..."
	./UFTest
	@echo "\nRunning Algorithms tests..."
	./AlgTest

# Check for memory leaks in main program
valgrind: Main
	$(VALGRIND) ./Main

# Check for memory leaks in all test programs
valgrind-test: test
	$(VALGRIND) ./GraphTest
	$(VALGRIND) ./QueueTest
	$(VALGRIND) ./PQTest
	$(VALGRIND) ./UFTest
	$(VALGRIND) ./AlgTest

# Rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean temporary files
clean:
	rm -f *.o Main GraphTest QueueTest PQTest UFTest AlgTest