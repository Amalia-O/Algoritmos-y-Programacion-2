all: TP2.exe

TP2.exe: TP2.o Lista.o Nodo.o LecturaParadas.o
	g++ TP2.o Lista.o Nodo.o LecturaParadas.o -o TP2.exe
	
TP2.o: TP2.cpp
	g++ -c TP2.cpp
	
Lista.o: Lista.cpp Lista.h
	g++ -c Lista.cpp

Nodo.o: Nodo.cpp Nodo.h
	g++ -c Nodo.cpp
	
LecturaParadas.o: LecturaParadas.cpp LecturaParadas.h
	g++ -c LecturaParadas.cpp

clean:
	rm *.o TP2.exe