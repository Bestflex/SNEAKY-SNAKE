all: bin/main_sdl bin/main_txt

bin/main_txt: obj/main_txt.o obj/txtJeu.o obj/winTxt.o obj/Jeu.o obj/Terrain.o obj/Fruit.o obj/Serpent.o obj/Serpent2.o obj/Extra.o
	g++ -g obj/main_txt.o obj/txtJeu.o obj/winTxt.o obj/Jeu.o obj/Terrain.o obj/Fruit.o obj/Serpent.o obj/Serpent2.o obj/Extra.o  -o bin/main_txt

bin/main_sdl:  obj/main_sdl.o obj/sdlJeu.o obj/Jeu.o obj/Terrain.o obj/Fruit.o obj/Serpent.o obj/Serpent2.o obj/Extra.o
	g++ -g obj/main_sdl.o obj/sdlJeu.o obj/Jeu.o obj/Terrain.o obj/Fruit.o obj/Serpent.o obj/Serpent2.o obj/Extra.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -o bin/main_sdl

#Creation des objets

obj/sdlJeu.o: src/sdlJeu.cpp src/sdlJeu.h src/Jeu.h
	g++ -g -Wall -c src/sdlJeu.cpp -I /usr/include/SDL2 -I src -o obj/sdlJeu.o

obj/main_sdl.o: src/main_sdl.cpp src/sdlJeu.h
	g++ -g -Wall -c src/main_sdl.cpp -I /usr/include/SDL2 -I src -o obj/main_sdl.o

obj/main_txt.o: src/main_txt.cpp src/winTxt.h src/txtJeu.h src/Jeu.h src/Terrain.h src/Fruit.h src/Serpent.h
	g++ -g -Wall -c src/main_txt.cpp -o obj/main_txt.o

obj/Fruit.o: src/Fruit.cpp src/Fruit.h src/Serpent.h src/Serpent2.h src/Terrain.h src/Extra.h
	g++ -g -Wall -c src/Fruit.cpp -o obj/Fruit.o

obj/Serpent.o: src/Serpent.cpp src/Serpent.h src/Terrain.h
	g++ -g -Wall -c src/Serpent.cpp -o obj/Serpent.o

obj/Serpent2.o: src/Serpent2.cpp src/Serpent2.h src/Terrain.h
	g++ -g -Wall -c src/Serpent2.cpp -o obj/Serpent2.o

obj/Terrain.o: src/Terrain.cpp src/Terrain.h
	g++ -g -Wall -c src/Terrain.cpp -o obj/Terrain.o

obj/Jeu.o: src/Jeu.cpp src/Jeu.h src/Terrain.h src/Fruit.h src/Serpent.h src/Serpent2.h src/Extra.h
	g++ -g -Wall -c src/Jeu.cpp -o obj/Jeu.o

obj/txtJeu.o: src/txtJeu.cpp src/txtJeu.h src/Jeu.h
	g++ -g -Wall -c src/txtJeu.cpp -o obj/txtJeu.o

obj/winTxt.o: src/winTxt.cpp src/winTxt.h
	g++ -g -Wall -c src/winTxt.cpp -o obj/winTxt.o

obj/Extra.o: src/Extra.cpp src/Extra.h
	g++ -g -Wall -c src/Extra.cpp -o obj/Extra.o

#Commande clean pour supprimer les objets et les executables 

clean:
	rm obj/*.o
	rm bin/*
