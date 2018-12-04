all : main.o recvFloat.o sendFloat.o saveData.o clearData.o 
	g++ main.o -o superviseur recvFloat.o sendFloat.o saveData.o clearData.o 

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

clean:
	rm -rf *.o

mrproper: clean
	rm -rf superviseur
