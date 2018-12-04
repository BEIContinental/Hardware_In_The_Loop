all : main.o saveData.o platform.o ert_main.o sendFloat.o recvFloat.o
	g++ main.o -o simulation saveData.o platform.o ert_main.o sendFloat.o recvFloat.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

ert_main.o : ert_main.cpp
	g++ -c ert_main.cpp -o ert_main.o

platform.o : platform.cpp
	g++ -c platform.cpp -o platform.o

saveData.o : saveData.cpp
	g++ -c saveData.cpp -o saveData.o

sendFloat.o : sendFloat.cpp
	g++ -c sendFloat.cpp -o sendFloat.o

recvFloat.o : recvFloat.cpp
	g++ -c recvFloat.cpp -o recvFloat.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf simulation
