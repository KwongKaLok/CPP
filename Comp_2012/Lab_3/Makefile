CPPFLAGS = -std=c++11
all: main.exe

main.exe: main.o events-query.o school-namespaces.o
	g++ $(CPPFLAGS) -o $@ main.o events-query.o school-namespaces.o

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -f  *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe