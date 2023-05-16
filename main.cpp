#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;

#include "Point.hpp"
#include "Vecteur.hpp"
#include "Couleur.hpp"
#include "Rayon.hpp"
#include "Objet.hpp"
#include "Sphere.hpp"

#include "InfoInterception.hpp"

int main() {
    Window window(VideoMode(600, 600), "Ma premiere fenetre SFML ! ");

    // Boucle principale
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
    }
    return 0;
}