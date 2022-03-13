CPPFLAGS = -std=c++11 
all: main.exe

main.exe: polynomial.o main.o
	g++ -o $@ $(CPPFLAGS) polynomial.o main.o


%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f  *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
