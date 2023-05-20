   #include "Objet.hpp"
   
   
   /* Constructeur */
    Objet::Objet(Couleur kd, double kr)
    : m_kr(kr), m_kd(kd)
    { 

    }


    /* Renvoie kd*/
    Couleur Objet::get_kd(){
        return m_kd;
    }
    /* Change la valeur de kd*/
    void Objet::set_kd(Couleur kd){
        m_kd = kd;
    }
    

    /* Renvoie kr*/
    double Objet::get_kr(){
        return m_kr;
    }
    /* Change la valeur de kr*/
    void Objet::set_kr(double kr){
        m_kr = kr;
    }

InfoInterception Objet::intersection(Rayon ray) {
    return InfoInterception(false);
}

Rayon Objet::rayon_reflechi(Point p, Source src) {
    return Rayon(Point(0, 0, 0), Vecteur(0, 0, 0));
}

bool Objet::visible(std::vector<Objet>, int j, Point p, Source src){return false;}
Vecteur Objet::vecteur_normal(Point p){return Vecteur(0,0,0);}

/*Cherche le point matériel d'un objet du tableau objets le plus proche sur la trajectoire du rayon et 
renvoie un objet InfoInterception caractéristique de l'interception */
InfoInterception interception(std::vector<Objet> objets, Rayon ray){
	int distance_max = 0;
	
	//L'infoInterception qu'on va renvoyer à la fin, c'est à dire l'interception avec le plus proche objet.
	// La valeur de base est "pas d'interception"
	InfoInterception infos_finales = InfoInterception(false); 
	
	for(int i = 0; i < objets.size(); i++){ //Pour tous les objets de la liste on teste si il y a intersection avec le rayon
		InfoInterception infos = objets[i].intersection(ray); //infos sur la potentielle intersection
		infos.set_j(i);
		//Si il y a eu intersection et si l'objet est plus proche que le plus proche atteint jusqu'à présent		
		if(infos.get_a_atteint() && infos.get_distance() >= distance_max){ 
			infos_finales = infos; //On actualise avec le plus proche objet découvert jusqu'à présent
		}
	}
	
	return infos_finales;
}

/*Renvoie un vector<InfoInterception> contenant une suite d'infoInterception 
correspondant aux rmax réflexions successives du rayon */
std::vector<InfoInterception> reflexions(std::vector<Objet> objets, int rmax, Rayon ray){
        Rayon rayon = ray;
	std::vector<InfoInterception> infos_tab; //Suite d'infoInterception correspondant aux rmax réflexions successives du rayon
	for(int i = 0; i<rmax; i++){
		InfoInterception infos = interception(objets, rayon);
		if(infos.get_a_atteint()){
			Source defaut = Source(rayon.get_origine(), Couleur(0, 0, 0));
			rayon = objets[infos.get_j()].rayon_reflechi(infos.get_point_interception(), defaut);
			infos_tab.push_back(infos);
		}
	}
	return infos_tab;
}


Couleur couleur_diffusion(Point point, std::vector<Objet> objets, int j, std::vector<Source> sources){
	Couleur resCouleur = Couleur(0, 0, 0);
	for(int i = 0; i<sources.size(); i++){
		if(objets[j].visible(objets, j, point, sources[i])){
			Rayon nouveau_rayon = Rayon(sources[i].get_point(), point);
			Couleur couleurDiffuseeSource_i = nouveau_rayon.couleur_diffusee(sources[i].get_couleur(), objets[j].vecteur_normal(point), objets[i].get_kd());
			resCouleur += couleurDiffuseeSource_i;
		}
	}
	return resCouleur;
}


Couleur couleur_percue(Rayon rayon, int rmax, Couleur fond, std::vector<Objet> objets, int j, std::vector<Source> sources){
	std::vector<InfoInterception> liste_reflexions = reflexions(objets, rmax, rayon);
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
	

