CPPFLAGS = -std=c++11

all: lab4.exe

lab4.exe: ParkingLot.o Truck.o PrivateCar.o Bus.o Vehicle.o main.cpp
	g++ -o $@ $(CPPFLAGS) ParkingLot.o PrivateCar.o Truck.o Bus.o Vehicle.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
