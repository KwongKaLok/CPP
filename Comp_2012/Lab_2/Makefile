CPPFLAGS = -std=c++11

all: lab2.exe

lab2.exe: event-ticket.o person.o bookingsystem.o main.o
	g++ -o $@ $(CPPFLAGS) event-ticket.o person.o bookingsystem.o main.o

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
