CPPFLAGS = -std=c++11

all: lab5.exe

lab5.exe: Employee.o Manager.o Technician.o TechnicianLeader.o main.o
	g++ -o $@ $(CPPFLAGS) Employee.o Manager.o Technician.o TechnicianLeader.o main.o

%.o: %.cpp
	g++ $(CPPFLAGS) -c $<

depend:
	makedepend *.cpp

clean:
# On Windows, use: del *.o *.exe
	del *.o *.exe
# On Linux or MacOS, use: 
# rm -f *.o *.exe


# DO NOT DELETE

Employee.o: Employee.h
Manager.o: Manager.h Employee.h
Technician.o: Technician.h Employee.h
TechnicianLeader.o: TechnicianLeader.h Technician.h Employee.h
main.o: Employee.h Manager.h TechnicianLeader.h Technician.h
