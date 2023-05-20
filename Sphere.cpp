#include "Sphere.hpp"
#include <stdio.h>
#include <iostream>
#include "Rayon.hpp"
#include "Camera.hpp"



/*Constructeur*/
Sphere::Sphere(Point centre, double rayon, Couleur couleur_objet, Couleur kd, double kr, double lisse) :
Objet(couleur_objet, kd, kr, lisse), m_centre(centre), m_rayon(rayon) 
{

}


InfoInterception Sphere::intersection(Rayon ray) {
    Vecteur origineRayAbs = Vecteur(m_centre, ray.get_origine()); 

    double a = ps(ray.get_direction().unitaire(), ray.get_direction().unitaire());
    double x = ray.get_direction().unitaire().get_x();
    double y = ray.get_direction().unitaire().get_y();
    double z = ray.get_direction().unitaire().get_z();
    double b = 2 * ps(origineRayAbs, ray.get_direction().unitaire());
    double c = ps(origineRayAbs, origineRayAbs) - m_rayon * m_rayon;
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        double distance = (-b - sqrt(discriminant)) / (2 * a);
        

        if (distance >= 0) {
			Point pt = ray.point_rayon(distance);
            return InfoInterception(true, distance, pt, this->vecteur_normal(pt), 0);
        }
	} 
	return InfoInterception(false);
    
    
}


Vecteur Sphere::vecteur_normal(Point p) {
    return Vecteur(m_centre, p).unitaire();
}



bool Sphere::au_dessus(Point point, Source source){
	if(ps(this->vecteur_normal(point), Vecteur(point, source.get_point())) >= 0){
		return true;
	}
	else{
		return false;
	}
}




/* Renvoie true si le point de la surface est visible
    par la source (argument) */
bool Sphere::visible(std::vector<Sphere> objets, Point point, Source source, int indice){
	if(this->au_dessus(point, source)){
		Rayon rayon = Rayon(source.get_point(), point);
		for(int i = 0; i < objets.size(); i++){
			InfoInterception infos = objets[i].intersection(rayon);
			double distance = Vecteur(source.get_point(), point).norme();
			//printf("kr = %f\n", objets[i].get_kr());
			//printf("A atteint : %d, distance à l'objet %f, distance à la source %f\n", infos.get_a_atteint(), infos.get_distance(), distance);
			//printf("adresse %p\n", &objets[i]); 
			if((indice != i) && infos.get_a_atteint() && infos.get_distance() < distance){
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
Rayon Sphere::rayon_reflechi(Point point, Source source){
	Vecteur u = Vecteur(source.get_point(), point).unitaire();
	Vecteur v = this->vecteur_normal(point);
	Vecteur w = u  + (-2 * ps(u, v)) * v;
	return Rayon(point, w);
}


/*Cherche le point matériel d'un objet du tableau objets le plus proche sur la trajectoire du rayon et 
renvoie un objet InfoInterception caractéristique de l'interception */
InfoInterception interception(std::vector<Sphere> objets, Rayon ray){
	double distance_max = 9999999;
	
	//L'infoInterception qu'on va renvoyer à la fin, c'est à dire l'interception avec le plus proche objet.
	// La valeur de base est "pas d'interception"
	InfoInterception infos_finales = InfoInterception(false); 
	
	for(int i = 0; i < objets.size(); i++){ //Pour tous les objets de la liste on teste si il y a intersection avec le rayon
		InfoInterception infos = objets[i].intersection(ray); //infos sur la potentielle intersection
		infos.set_j(i);
		//Si il y a eu intersection et si l'objet est plus proche que le plus proche atteint jusqu'à présent		
		if(infos.get_a_atteint()){ 
			if (infos.get_distance() <= distance_max) {
			infos_finales = infos; //On actualise avec le plus proche objet découvert jusqu'à présent
			distance_max = infos.get_distance();
			}
		}
	}
	
	return infos_finales;
}




/*Renvoie un vector<InfoInterception> contenant une suite d'infoInterception 
correspondant aux rmax réflexions successives du rayon */
std::vector<InfoInterception> reflexions(std::vector<Sphere> objets, Rayon ray){
        Rayon rayon = ray;
	std::vector<InfoInterception> infos_tab; //Suite d'infoInterception correspondant aux rmax réflexions successives du rayon
	for(int i = 0; i<rmax; i++){
		InfoInterception infos = interception(objets, rayon);
		if(infos.get_a_atteint()){
			Source defaut = Source(rayon.get_origine(), Couleur(0, 0, 0));
			rayon = objets[infos.get_j()].rayon_reflechi(infos.get_point_interception(), defaut);

			infos_tab.push_back(infos);
		} else {
			break;
		}
	}
	return infos_tab;
}


Couleur couleur_diffusion(Point point, std::vector<Sphere> objets, int j, std::vector<Source> sources){
	Couleur resCouleur = Couleur(0, 0, 0);
	for(int i = 0; i<sources.size(); i++){
		if(objets[j].visible(objets, point, sources[i], j)){
			Rayon nouveau_rayon = Rayon(sources[i].get_point(), point);
			Couleur couleurDiffuseeSource_i = nouveau_rayon.couleur_diffusee(sources[i].get_couleur(), objets[j].vecteur_normal(point), objets[j].get_kd());
			resCouleur += couleurDiffuseeSource_i;
		}
	}
	return resCouleur;
}


Couleur couleur_percue(Rayon rayon, Couleur fond, std::vector<Sphere> objets, std::vector<Source> sources){
	std::vector<InfoInterception> liste_reflexions = reflexions(objets, rayon);
	double coeff_reflexion = 1;
	Couleur c_res = Couleur(0, 0, 0);
	if(liste_reflexions.size() == 0){
		return fond;
	}
	else{
		for(int i = 0; i<liste_reflexions.size(); i++){
			c_res += couleur_diffusion(liste_reflexions[i].get_point_interception(), objets, liste_reflexions[i].get_j(), sources).mult_scalaire(coeff_reflexion);
			coeff_reflexion *=  objets[liste_reflexions[i].get_j()].get_kr();
		}
		return c_res;
	}
}


Vecteur direction_aleatoire(int seed) {
	double x = valeur_aleatoire_normal(seed*10000);
	double y = valeur_aleatoire_normal(seed*10000 + 1);
	double z = valeur_aleatoire_normal(seed*10000 + 2);
	Vecteur v = Vecteur(x, y, z);
	return v.unitaire();
}

Vecteur direction_aleatoire_signe(Vecteur normal, int seed) {
	Vecteur dir = direction_aleatoire(seed);
	double signe = ps(normal, dir);
	if (signe >= 0) {
		return dir;
	} else {
		return dir.oppose();
	}
}

Couleur rayon_couleur(Rayon ray, std::vector<Sphere> objets, Couleur fond, int seed) {
	Rayon rayon = ray;
	Couleur lumiere_recue = Couleur(0, 0, 0);
	Couleur couleur_rayon = Couleur(1, 1, 1);

	for (int i=0; i <= rmax; i++) {
		InfoInterception info = interception(objets, rayon);
		if (info.get_a_atteint()) {
			Source src = Source(rayon.get_origine(), Couleur(0, 0, 0));
			rayon.set_origine(info.get_point_interception());
			Vecteur direction_diffuse = info.get_vecteur_normal() + direction_aleatoire(seed);
			Vecteur direction_speculaire = objets[info.get_j()].rayon_reflechi(info.get_point_interception(), src).get_direction();

			rayon.set_direction(lerp(info.get_vecteur_normal(), direction_aleatoire(seed), objets[info.get_j()].get_lisse()));
			
			Sphere s_intersection = objets[info.get_j()];
			Couleur lumiere_emise = s_intersection.get_kr() * s_intersection.get_kd();
			//double intensitelumineuse = ps(info.get_vecteur_normal(), rayon.get_direction().unitaire());
			lumiere_recue += lumiere_emise * couleur_rayon;
			couleur_rayon *= s_intersection.get_couleur_objet();
		}
		else {
			break;
		}
	}

	return lumiere_recue;
}

std::vector<InfoInterception> reflexions2(std::vector<Sphere> objets, Rayon ray, int seed){
        Rayon rayon = ray;
	std::vector<InfoInterception> infos_tab; //Suite d'infoInterception correspondant aux rmax réflexions successives du rayon
	for(int i = 0; i<rmax; i++){
		InfoInterception infos = interception(objets, rayon);
		if(infos.get_a_atteint()){
			rayon.set_origine(infos.get_point_interception());
			rayon.set_direction(infos.get_vecteur_normal() + direction_aleatoire(seed));
			infos_tab.push_back(infos);
		} else {
			break;
		}
	}
	return infos_tab;
}

Couleur couleur_percue2(Rayon rayon, Couleur fond, std::vector<Sphere> objets, std::vector<Source> sources, int seed){
	std::vector<InfoInterception> liste_reflexions = reflexions2(objets, rayon, seed);
	double coeff_reflexion = 1;
	Couleur c_res = Couleur(0, 0, 0);
	if(liste_reflexions.size() == 0){
		return fond;
	}
	else{
		for(int i = 0; i<liste_reflexions.size(); i++){
			c_res += couleur_diffusion(liste_reflexions[i].get_point_interception(), objets, liste_reflexions[i].get_j(), sources).mult_scalaire(coeff_reflexion);
			coeff_reflexion *=  objets[liste_reflexions[i].get_j()].get_kr();
		}
		return c_res;
	}
}



