#include "Source.hpp"



/* Constructeur */
Source::Source(Point point, Couleur couleur):
m_point(point), m_couleur(couleur)
{

}

/*Renvoie la couleur de la source*/
Couleur Source::get_couleur(){
	return m_couleur;
}

/*Renvoie le point de la source*/
Point Source::get_point(){
	return m_point;
}

/*Change le point de la source*/
void Source::set_point(Point point){
	m_point = point;
}

/*Change la couleur de la source*/
void Source::set_couleur(Couleur couleur){
	m_couleur = couleur;
}
