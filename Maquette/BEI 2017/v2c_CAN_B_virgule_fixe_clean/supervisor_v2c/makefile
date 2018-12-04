all : main.o pere.o fils1.o fils2.o sendInt16.o recvInt16.o fixedPoint.o saveData.o clearData.o
	g++ main.o -o supervisor pere.o fils1.o fils2.o sendInt16.o recvInt16.o fixedPoint.o saveData.o clearData.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

pere.o : pere.cpp
	g++ -c pere.cpp -o pere.o

fils1.o : fils1.cpp
	g++ -c fils1.cpp -o fils1.o

fils2.o : fils2.cpp
	g++ -c fils2.cpp -o fils2.o

sendInt16.o : sendInt16.cpp
	g++ -c sendInt16.cpp -o sendInt16.o

recvInt16.o : recvInt16.cpp
	g++ -c recvInt16.cpp -o recvInt16.o

fixedPoint.o : fixedPoint.cpp
	g++ -c fixedPoint.cpp -o fixedPoint.o

saveData.o : saveData.cpp
	g++ -c saveData.cpp -o saveData.o

clearData.o : clearData.cpp
	g++ -c clearData.cpp -o clearData.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf supervisor
