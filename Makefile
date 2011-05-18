CC = g++
CXXFLAGS = -g -Wall -I /opt/local/include -I source/
LDFLAGS =  -g -L /opt/local/lib -l cppunit
TESTOBJS := $(patsubst %.cpp,%.o,$(wildcard tests/*.cpp))
RUNNEROBJS := $(patsubst %.cpp,%.o,$(wildcard source/*.cpp))

testrunner: $(TESTOBJS) $(RUNNEROBJS)
	$(CC) $(LDFLAGS) source/*.o tests/*.o -o testrunner

clean:
	rm source/*.o
	rm tests/*.o
	rm testrunner
	rm runner
