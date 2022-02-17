# Definition of variables
SRCS	= bulb.cpp lamp.cpp lamp-test.cpp
OBJS	= bulb.o lamp.o lamp-test.o
INCS	= bulb.h lamp.h

# Rules: 
# target: dependencies
#   command used to create the target
lamp-test: $(OBJS) 
	g++ -o lamp-test $(OBJS)

bulb.o: bulb.cpp
	g++ -c bulb.cpp

lamp.o: lamp.cpp
	g++ -c lamp.cpp

lamp-test.o: lamp-test.cpp 
	g++ -c lamp-test.cpp

clean:;	/bin/rm lamp-test *.o *.bak

# Utility 'makedepend' finds the .h dependencies automatically
depend:;	makedepend $(SRCS)
# DO NOT DELETE

bulb.o: bulb.h
lamp.o: lamp.h bulb.h
lamp-test.o: lamp.h bulb.h
