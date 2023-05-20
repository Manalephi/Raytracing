
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "Rayon.hpp"
#include "Point.hpp"
#include "Source.hpp"
#include "InfoInterception.hpp"
#include "Couleur.hpp"
#include "Objet.hpp"
#include "Sphere.hpp"
#include "Vecteur.hpp"
#include "Camera.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



int main() {
	
	
	Sphere s1 = Sphere(Point(600, 400, -1000), 200, Couleur(0.2, 0.7, 0.6), 0.9);
	Sphere s2 = Sphere(Point(200, 300, -1000), 200, Couleur(0.3, 0.2, 0.8), 1);
	Source e1 = Source(Point(0, -100, 100), Couleur(1, 1, 1));
	std::vector<Sphere> objets;
	std::vector<Source> sources;
	objets.push_back(s1);
	objets.push_back(s2);
	sources.push_back(e1);
	Point oeil = Point(200, 200, 1000);



	sf::RenderWindow window(sf::VideoMode(N, N, 32), "My window");
	sf::Texture texture;
	texture.create(N, N);
	sf::Sprite sprite(texture);
	sf::Uint8* pixels = new sf::Uint8[N * N * 4];

	lancer2(oeil, Couleur(0, 0, 0), 20,  pixels, objets, sources);
	texture.update(pixels);
	window.draw(sprite);
	window.display();
	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		
	}

	delete [] pixels;
	
	return 0;
}



//Indices 
//Camera






