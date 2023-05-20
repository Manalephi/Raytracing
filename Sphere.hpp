#ifndef SPHERE_HPP_INCLUDED
#define SPHERE_HPP_INCLUDED

#include "Point.hpp"
#include "Vecteur.hpp"
#include "Source.hpp"

#include "InfoInterception.hpp"
#include <math.h>

#include "Objet.hpp"

class Sphere: public Objet{
    
    public:

    /* Constructeur */
    Sphere(Point centre, double rayon, Couleur kd, double kr);

    /* Getteur rayon */
    double get_rayon();

    /* Setteur rayon */
    void set_rayon(double m_rayon);

    /* Getteur centre */
    Point get_centre();

    /* Setteur centre */
    void set_centre(Point centre);

    /* Renvoie l'infoInterception d'une intersection entre
    un objet et un rayon */
    InfoInterception intersection(Rayon ray);

    /* Renvoie le vecteur normal par rapport à un point
    de la surface de l'objet */
    Vecteur vecteur_normal(Point p);

    /*est-on au dessus de la sphère par rapport à la source*/
    bool au_dessus(Point point, Source source);

    /* Renvoie true si le point de la surface est visible
    par la source (argument) */
    bool visible(std::vector<Sphere>, Point p, Source src, int indice);

    /* Renvoie le rayon réfléchi à une source selon le point
    p de la surface de l'objet */
    Rayon rayon_reflechi(Point p, Source src);

    private :

    double m_rayon;
    Point m_centre;
};



/*Cherche le point matériel d'un objet du tableau objets le plus proche sur la trajectoire du rayon et 
renvoie un objet InfoInterception caractéristique de l'interception */
InfoInterception interception(std::vector<Sphere> objets, Rayon ray);
	
/*Renvoie un vector<InfoInterception> contenant une suite d'infoInterception 
correspondant aux réflexions successives du rayon */
std::vector<InfoInterception> reflexions(std::vector<Sphere> objets, Rayon ray, int rmax); 

Couleur couleur_diffusion(Point point, std::vector<Sphere> objets, int j, std::vector<Source> sources);
Couleur couleur_percue(Rayon rayon, int rmax, Couleur fond, std::vector<Sphere> objets, std::vector<Source> sources);

Vecteur direction_aleatoire(int seed);

Vecteur direction_aleatoire_signe(Vecteur normal, int seed);

#endif // SPHERE_HPP_INCLUDED
