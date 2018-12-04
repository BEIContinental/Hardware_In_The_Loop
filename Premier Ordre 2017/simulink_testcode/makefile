all : ert_main.o simulink_testcode.o saveData.o clearData.o
	g++ ert_main.o simulink_testcode.o saveData.o clearData.o -o simulation

ert_main.o :
	g++ -c ert_main.cpp -o ert_main.o

simulink_testcode.o :
	g++ -c simulink_testcode.cpp -o simulink_testcode.o

saveData.o :
	g++ -c saveData.cpp -o saveData.o

clearData.o :
	g++ -c clearData.cpp -o clearData.o

clean :
	rm *.o

mrproper : clean
	rm simulation
