   #include "Objet.hpp"
   
   
   /* Constructeur */
    Objet::Objet(double kd, double kr)
    : m_kr(kr), m_kd(kd)
    { 

    }


    /* Renvoie kd*/
    double Objet::get_kd(){
        return m_kd;
    }
    /* Change la valeur de kd*/
    void Objet::set_kd(double kd){
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

Rayon Objet::rayon_reflechi(Point p, Point src) {
    return Rayon(Point(0, 0, 0), Vecteur(0, 0, 0));
}

/*Cherche le point matériel d'un objet du tableau objets le plus proche sur la trajectoire du rayon et 
renvoie un objet InfoInterception caractéristique de l'interception */
InfoInterception interception(std::vector<Objet> objets, Rayon ray){
	int distance_max = 0;
	
	//L'infoInterception qu'on va renvoyer à la fin, c'est à dire l'interception avec le plus proche objet.
	// La valeur de base est "pas d'interception"
	InfoInterception infos_finales = InfoInterception(false); 
	
	for(int i = 0; i < objets.size(); i++){ //Pour tous les objets de la liste on teste si il y a intersection avec le rayon
		InfoInterception infos = objets[i].intersection(ray); //infos sur la potentielle intersection
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
				rayon = objets[infos.get_j()].rayon_reflechi(infos.get_point_interception(), rayon.get_origine());
				infos_tab.push_back(infos);
			}
		}
		return infos_tab;
	}


