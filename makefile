CC = g++
CFLAGS = -Wall -ggdb

all: bin/main bin/mainPerformance



bin/main: obj/main.o obj/collec.o obj/Arbre.o obj/ARN.o obj/ElementA.o
	$(CC) $(CFLAGS) obj/main.o obj/collec.o obj/Arbre.o obj/ARN.o obj/ElementA.o -o bin/main

bin/mainPerformance: obj/mainPerformance.o obj/Arbre.o obj/ARN.o obj/ElementA.o
	$(CC) $(CFLAGS) obj/mainPerformance.o obj/Arbre.o obj/ARN.o obj/ElementA.o -o bin/mainPerformance

obj/main.o: src/main.cpp src/collec.h src/Arbre_binaire/Arbre.h src/ARN/ARN.h src/ElementA.h
	$(CC) $(CFLAGS) -c src/main.cpp -o obj/main.o



obj/collec.o: src/collec.cpp src/collec.h src/Arbre_binaire/Arbre.h src/ARN/ARN.h src/ElementA.h
	$(CC) $(CFLAGS) -c src/collec.cpp -o obj/collec.o



obj/Arbre.o: src/Arbre_binaire/Arbre.cpp src/Arbre_binaire/Arbre.h src/ElementA.h
	$(CC) $(CFLAGS) -c src/Arbre_binaire/Arbre.cpp -o obj/Arbre.o

obj/ARN.o: src/ARN/ARN.cpp src/ARN/ARN.h src/ElementA.h
	$(CC) $(CFLAGS) -c src/ARN/ARN.cpp -o obj/ARN.o



obj/ElementA.o: src/ElementA.cpp src/ElementA.h
	$(CC) $(CFLAGS) -c src/ElementA.cpp -o obj/ElementA.o


obj/mainPerformance.o: src/mainPerformance.cpp src/Arbre_binaire/Arbre.h src/ARN/ARN.h src/ElementA.h 
	$(CC) $(CFLAGS) -c src/mainPerformance.cpp -o obj/mainPerformance.o

runmain :
	bin/main

runperf :
	bin/mainPerformance

clean :
	rm obj/*