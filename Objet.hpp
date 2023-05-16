#ifndef OBJET_HPP_INCLUDED
#define OBJET_HPP_INCLUDED


#include "Point.hpp"
#include "Vecteur.hpp"
#include <vector>

#include "InfoInterception.hpp"


#include "Rayon.hpp"



class Objet
{
    public:

    /* Constructeur */
    Objet(double kd, double kr);

    /* Renvoie kd*/
    double get_kd();
    /* Change la valeur de kd*/
    void set_kd(double kd);

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
    bool visible(std::vector<Objet>, int j, Point p, Point src);

    /* Renvoie le rayon réfléchi à une source selon le point
    p de la surface de l'objet */
    Rayon rayon_reflechi(Point p, Point src);

    private:

    double m_kd; // indice de diffusion
    double m_kr; // indice de réflexion
};

/*Cherche le point matériel d'un objet du tableau objets le plus proche sur la trajectoire du rayon et 
renvoie un objet InfoInterception caractéristique de l'interception */
InfoInterception interception(std::vector<Objet> objets, Rayon ray);
	
/*Renvoie un vector<InfoInterception> contenant une suite d'infoInterception 
correspondant aux réflexions successives du rayon */
std::vector<InfoInterception> reflexions(std::vector<Objet> objets, Rayon ray, int rmax); 



#endif //OBJET_HPP_INCLUDED