#ifndef SPHERE_HPP_INCLUDED
#define SPHERE_HPP_INCLUDED

#include "Point.hpp"
#include "Vecteur.hpp"

#include "InfoInterception.hpp"
#include <math.h>

#include "Objet.hpp"

class Sphere: public Objet{
    
    public:

    /* Constructeur */
    Sphere(Point centre, double rayon, double kd, double kr);

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
    bool au_dessus(Point point, Point source);

    /* Renvoie true si le point de la surface est visible
    par la source (argument) */
    bool visible(std::vector<Objet>, Point p, Point src);

    /* Renvoie le rayon réfléchi à une source selon le point
    p de la surface de l'objet */
    Rayon rayon_reflechi(Point p, Point src);
    
    private :

    double m_rayon;
    Point m_centre;
};


#endif // SPHERE_HPP_INCLUDED