#ifndef RAYON_HPP_INCLUDED
#define RAYON_HPP_INCLUDED

#include <vector>
#include "Point.hpp"
#include "Vecteur.hpp"
#include "Couleur.hpp"


#include "InfoInterception.hpp"



class Rayon {

	public:

	/*Constructeur de la classe Rayon avec un Point et un Vecteur*/
	Rayon(Point origine, Vecteur direction);
	/*Constructeur de la classe Rayon avec deux points*/
	Rayon(Point a, Point b);

	/*Retourne m_origine*/
	Point get_origine();
	/*Change la valeur de m_origine avec origine*/
	void set_origine(Point origine);
	
	/*Retourne m_origine*/
	Vecteur get_direction();
	/*Change la valeur de m_direction avec direction*/
	void set_direction(Vecteur direction);
	
	/*Donne le point du rayon à une distance t de l'origine du rayon avec t un réel positif*/
	Point point_rayon(double t);
	
        /*Renvoie la couleur diffusee par le rayon lors d'une intersection*/
        Couleur couleur_diffusee(Couleur couleur_source, Vecteur normal, Couleur couleur_diffusion);
	 
	
	private:
	Point m_origine; //Origine du rayon
	Vecteur m_direction; //Vecteur directeur du rayon

};

double valeur_aleatoire(int seed);

double valeur_aleatoire_normal(int seed);


#endif //RAYON_HPP_INCLUDED

