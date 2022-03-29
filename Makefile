all: bin/main_txt

bin/main_txt: obj/main_txt.o obj/txtJeu.o obj/winTxt.o obj/Jeu.o obj/Terrain.o obj/Fruit.o obj/Serpent.o
	g++ -g obj/main_txt.o obj/txtJeu.o obj/winTxt.o obj/Jeu.o obj/Terrain.o obj/Fruit.o obj/Serpent.o -o bin/test

obj/main_txt.o: src/main_txt.cpp src/winTxt.h src/txtJeu.h src/Jeu.h src/Terrain.h src/Fruit.h src/Serpent.h
	g++ -g -Wall -c src/main_txt.cpp -o obj/main_txt.o

obj/Fruit.o: src/Fruit.cpp src/Fruit.h src/Serpent.h src/Terrain.h
	g++ -g -Wall -c src/Fruit.cpp -o obj/Fruit.o

obj/Serpent.o: src/Serpent.cpp src/Serpent.h src/Terrain.h
	g++ -g -Wall -c src/Serpent.cpp -o obj/Serpent.o

obj/Terrain.o: src/Terrain.cpp src/Terrain.h
	g++ -g -Wall -c src/Terrain.cpp -o obj/Terrain.o

obj/Jeu.o: src/Jeu.cpp src/Jeu.h src/Terrain.h src/Fruit.h src/Serpent.h
	g++ -g -Wall -c src/Jeu.cpp -o obj/Jeu.o

obj/txtJeu.o: src/txtJeu.cpp src/txtJeu.h src/Jeu.h
	g++ -g -Wall -c src/txtJeu.cpp -o obj/txtJeu.o

obj/winTxt.o: src/winTxt.cpp src/winTxt.h
	g++ -g -Wall -c src/winTxt.cpp -o obj/winTxt.o

clean:
	rm obj/*.o
	rm bin/*
