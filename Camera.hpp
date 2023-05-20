#ifndef CAMERA_HPP_INCLUDED
#define CAMERA_HPP_INCLUDED

#include "Point.hpp"
#include "Rayon.hpp"
#include "Couleur.hpp"
#include "InfoInterception.hpp"
#include "Sphere.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

#define N 600
#define delta 600

Point grille(int i, int j);

Rayon rayon_ecran(Point omega, int i, int j);

/* Lance des rayons, couleur calculé selon lambert */
void lancer(Point omega, Couleur fond, sf::Uint8 *pixels, std::vector<Sphere> objets, std::vector<Source> sources);

void lancer2(Point omega, Couleur fond, int rmax, sf::Uint8 *pixels, std::vector<Sphere> objets, std::vector<Source> sources);

#endif // CAMERA_HPP_INCLUDED









