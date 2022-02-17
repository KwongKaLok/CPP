CPPFLAGS = -std=c++11
all: main.exe

main.exe: openningMessage.o main.o QA.o
	g++ -o $@ $(CPPFLAGS) openningMessage.o main.o QA.o


%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f  *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
