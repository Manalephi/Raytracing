#include "Rayon.hpp"
#include <assert.h>
#include <math.h>



/*Constructeur de la classe Rayon avec un Point et un Vecteur*/
Rayon::Rayon(Point origine, Vecteur direction) :
m_origine(origine), m_direction(direction.unitaire())
{

}
/*Constructeur de la classe Rayon avec deux points*/
Rayon::Rayon(Point a, Point b) :
m_origine(a), m_direction(Vecteur(a, b).unitaire())
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

Couleur Rayon::couleur_diffusee(Couleur couleur_source, Vecteur normal, Couleur couleur_diffusion){
	double coeff = ps(normal.unitaire(), (this->m_direction.oppose().unitaire()));
	double rouge = (couleur_diffusion * couleur_source).get_r() * coeff;
	double vert = (couleur_diffusion * couleur_source).get_g() * coeff;
	double bleu = (couleur_diffusion * couleur_source).get_b() * coeff;
	return Couleur(rouge, vert, bleu);
}

// genere un nombre aleatoire
double valeur_aleatoire(int seed) {
	seed = seed * 747796405 + 2891336453;
	int result = ((seed >> ((seed >> 28) + 4)) ^ seed) * 277803737;
	result = (result >> 22) ^ result;
	return result / 4294967295.0;
}

double valeur_aleatoire_normal(int seed) {
	double theta = 2 * 3.1415926 * valeur_aleatoire(seed);
	double rho = sqrt(-2 * log(valeur_aleatoire(seed)));
	return rho * cos(theta);
}


