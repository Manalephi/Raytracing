#include "Sphere.hpp"


#include "Rayon.hpp"

/*Constructeur*/
Sphere::Sphere(Point centre, double rayon, double kd, double kr) :
Objet(kd, kr), m_centre(centre), m_rayon(rayon) 
{

}


InfoInterception Sphere::intersection(Rayon ray) {
    Vecteur OrigineRayAbs = Vecteur(m_centre, ray.get_origine()); 

    double a = ps(ray.get_direction().unitaire(), ray.get_direction().unitaire());
    double b = 2 * ps(OrigineRayAbs, OrigineRayAbs);
    double c = ps(OrigineRayAbs, OrigineRayAbs) - m_rayon * m_rayon;
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        double distance = (-b - sqrt(discriminant)) / (2 * a);
        Point pt = ray.point_rayon(distance);

        if (distance >= 0) {
            return InfoInterception(true, distance, pt, this->vecteur_normal(pt), 0);
        }
		return InfoInterception(false);
	}
        else {
            return InfoInterception(false);
        }
    }


Vecteur Sphere::vecteur_normal(Point p) {
    return Vecteur(m_centre, p).unitaire();
}



bool Sphere::au_dessus(Point point, Point source){
	if(ps(this->vecteur_normal(point), Vecteur(point, source)) >= 0){
		return true;
	}
	else{
		return false;
	}
}




/* Renvoie true si le point de la surface est visible
    par la source (argument) */
bool Sphere::visible(std::vector<Objet> objets, Point point, Point source){
	if(this->au_dessus(point, source)){
		Rayon rayon = Rayon(source, point);
		for(int i = 0; i < objets.size(); i++){
			if((this != &objets[i]) && 
			   (objets[i].intersection(rayon).get_a_atteint()) && 
			   (objets[i].intersection(rayon).get_distance() < Vecteur(source, point).norme())
			  ){
			  	return false;
			  }
		}
	}
	else{
		return false;
	}
	return true;
}


/* Renvoie le rayon réfléchi à une source selon le point point de la surface de l'objet */
Rayon Sphere::rayon_reflechi(Point point, Point source){
	Vecteur u = Vecteur(source, point).unitaire();
	Vecteur N = this->vecteur_normal(point);
	Vecteur w = u  + (-2 * ps(u, N)) * N;
	return Rayon(point, w);
}



