CXX=c++

CXXFLAGS=-fPIC -I/usr/local/include -m64


boost_serial.so:boost_serial.o
	$(CXX) -dynamiclib -undefined dynamic_lookup -o $@ $^
boost_serial.o:boost_serial.cpp
	$(CXX) $(CXXFLAGS) -c $<
clean:
	rm *.o *.
