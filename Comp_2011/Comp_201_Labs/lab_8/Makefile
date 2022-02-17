OBJS	= main.o util.o lab8.o
PROG	= lab8

$(PROG): $(OBJS)
	g++ -o lab8 $(OBJS)

main.o: main.cpp
	g++ -c main.cpp

util.o: util.cpp
	g++ -c util.cpp

lab8.o: lab8.cpp
	g++ -c lab8.cpp

clean:
	/bin/rm -f *.o *~ $(PROG)
