#include "Rayon.hpp"
#include <assert.h>




/*Constructeur de la classe Rayon avec un Point et un Vecteur*/
Rayon::Rayon(Point origine, Vecteur direction) :
m_origine(origine), m_direction(direction)
{

}
/*Constructeur de la classe Rayon avec deux points*/
Rayon::Rayon(Point a, Point b) :
m_origine(a), m_direction(Vecteur(a, b))
{
	
}

/*Retourne m_origine*/
Point Rayon::get_origine(){
	return m_origine;
} 
/*Change la valeur de m_origine avec origine*/
void Rayon::set_origine(Point origine){
	m_origine = origine;
}

/*Retourne m_origine*/
Vecteur Rayon::get_direction(){
	return m_direction;
}
/*Change la valeur de m_direction avec direction*/
void Rayon::set_direction(Vecteur direction){
	m_direction = direction;
}

/*Donne le point du rayon à une distance t de l'origine du rayon avec t un réel positif*/
Point Rayon::point_rayon(double t){
	assert(t>=0);
	double x = this->get_origine().get_x() + t * this->get_direction().get_x();
	double y = this->get_origine().get_y() + t * this->get_direction().get_y();
	double z = this->get_origine().get_z() + t * this->get_direction().get_z();
	
	return (Point(x, y, z));
}
