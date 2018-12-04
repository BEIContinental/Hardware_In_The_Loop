all : main.o recvFloat.o sendFloat.o saveData.o clearData.o consigne.o fils1.o fils2.o
	g++ main.o -o superviseur recvFloat.o sendFloat.o saveData.o clearData.o consigne.o fils1.o fils2.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

recvFloat.o : recvFloat.cpp
	g++ -c recvFloat.cpp -o recvFloat.o

sendFloat.o : sendFloat.cpp
	g++ -c sendFloat.cpp -o sendFloat.o

saveData.o : saveData.cpp
	g++ -c saveData.cpp -o saveData.o

clearData.o : clearData.cpp
	g++ -c clearData.cpp -o clearData.o

consigne.o : consigne.cpp
	g++ -c consigne.cpp -o consigne.o

fils1.o : fils1.cpp
	g++ -c fils1.cpp -o fils1.o

fils2.o : fils2.cpp
	g++ -c fils2.cpp -o fils2.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf superviseur
