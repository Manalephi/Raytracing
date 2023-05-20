#ifndef OBJET_HPP_INCLUDED
#define OBJET_HPP_INCLUDED


#include "Point.hpp"
#include "Vecteur.hpp"
#include "Source.hpp"
#include <vector>

#include "InfoInterception.hpp"


#include "Rayon.hpp"



class Objet
{
    public:

    /* Constructeur */
    Objet(Couleur kd, double kr);

    /* Renvoie kd*/
    Couleur get_kd();
    /* Change la valeur de kd*/
    void set_kd(Couleur kd);

    /* Renvoie kr*/
    double get_kr();
    /* Change la valeur de kr*/
    void set_kr(double kr);

    /* Renvoie l'infoInterception d'une intersection entre
    un objet et un rayon */
    InfoInterception intersection(Rayon ray);

    /* Renvoie le vecteur normal par rapport à un point
    de la surface de l'objet */
    Vecteur vecteur_normal(Point p);

    /* Renvoie true si le point de la surface est visible
    par la source (argument) */
    bool visible(std::vector<Objet>, int j, Point p, Source src);

    /* Renvoie le rayon réfléchi à une source selon le point
    p de la surface de l'objet */
    Rayon rayon_reflechi(Point p, Source src);

    private:

    Couleur m_kd; // indice de diffusion
    double m_kr; // indice de réflexion
};



#endif //OBJET_HPP_INCLUDED
