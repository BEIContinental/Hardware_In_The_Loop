all : main.o fixedPoint.o
	g++ main.o -o test fixedPoint.o
	
main.o : main.cpp
	g++ -c main.cpp -o main.o

fixedPoint.o : fixedPoint.cpp
	g++ -c fixedPoint.cpp -o fixedPoint.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf FixedPoint
