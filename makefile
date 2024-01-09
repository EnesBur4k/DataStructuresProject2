hepsi:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -c -I "./include" ./src/HucreDugum.cpp -o ./lib/HucreDugum.o
	g++ -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o
	g++ -c -I "./include" ./src/DokuDugum.cpp -o ./lib/DokuDugum.o
	g++ -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o
	g++ -c -I "./include" ./src/OrganDugum.cpp -o ./lib/OrganDugum.o
	g++ -c -I "./include" ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -c -I "./include" ./src/SistemDugum.cpp -o ./lib/SistemDugum.o
	g++ -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -c -I "./include" ./src/Kontrol.cpp -o ./lib/Kontrol.o
	g++ -c -I "./include" ./src/Queue.cpp -o ./lib/Queue.o
	g++ -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o
	g++ -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o	
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o

bagla:
	g++ ./lib/Hucre.o ./lib/HucreDugum.o ./lib/Doku.o ./lib/DokuDugum.o ./lib/Organ.o ./lib/OrganDugum.o ./lib/Sistem.o ./lib/SistemDugum.o ./lib/Organizma.o ./lib/Kontrol.o ./lib/Queue.o ./lib/Radix.o ./lib/IkiliAramaAgaci.o ./lib/main.o  -o ./bin/program

calistir:
	./bin/program.exe