#ifndef RAYON_HPP_INCLUDED
#define RAYON_HPP_INCLUDED

#include <vector>
#include "Point.hpp"
#include "Vecteur.hpp"



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
	
	
	 
	
	private:
	Point m_origine; //Origine du rayon
	Vecteur m_direction; //Vecteur directeur du rayon

};


#endif //RAYON_HPP_INCLUDED

