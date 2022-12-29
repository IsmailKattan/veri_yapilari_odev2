all : derle bagla calistir

derle : 
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/hucre.cpp -o ./lib/hucre.o
	g++ -c -I "./include" ./src/doku.cpp -o ./lib/doku.o
	g++ -c -I "./include" ./src/organ.cpp -o ./lib/organ.o
	g++ -c -I "./include" ./src/radix.cpp -o ./lib/radix.o
	g++ -c -I "./include" ./src/sistem.cpp -o ./lib/sistem.o
	g++ -c -I "./include" ./src/sistemnode.cpp -o ./lib/sistemnode.o
	g++ -c -I "./include" ./src/organizma.cpp -o ./lib/organizma.o
	g++ -c -I "./include" ./src/kontrol.cpp -o ./lib/kontrol.o
bagla : 
	g++ ./lib/kontrol.o ./lib/organizma.o ./lib/sistemnode.o ./lib/sistem.o ./lib/radix.o ./lib/organ.o ./lib/doku.o ./lib/hucre.o ./lib/main.o -o ./bin/program
calistir : 
	./bin/program