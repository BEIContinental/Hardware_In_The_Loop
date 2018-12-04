all : main.o LectureData.o somme.o sendFloat.o sendData.o recvFloat.o recvData.o saveData.o
	g++ main.o -o simulation  LectureData.o somme.o sendFloat.o sendData.o recvFloat.o recvData.o saveData.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

Lecture_Data.o : LectureData.cpp
	g++ -c LectureData.cpp -o LectureData.o

somme.o : somme.cpp
	g++ -c somme.cpp -o somme.o

sendFloat.o : sendFloat.cpp
	g++ -c sendFloat.cpp -o sendFloat.o

sendData.o : sendData.cpp
	g++ -c sendData.cpp -o sendData.o

recvFloat.o : recvFloat.cpp
	g++ -c recvFloat.cpp -o recvFloat.o

recvData.o : recvData.cpp
	g++ -c recvData.cpp -o recvData.o

saveData.o : saveData.cpp
	g++ -c saveData.cpp -o saveData.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf simulation
