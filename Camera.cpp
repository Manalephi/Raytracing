#include "Camera.hpp"

Point grille(int i, int j) {
    return Point((i + 0.5)*delta/((float)N), (j + 0.5)*delta/((float)N), 0);
}

Rayon rayon_ecran(Point omega, int i, int j) {
    return Rayon(omega, grille(i, j));
}

void lancer(Point omega, Couleur fond, sf::Uint8 *pixels, std::vector<Sphere> objets, std::vector<Source> sources) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            Rayon ray = rayon_ecran(omega, i, j);
            InfoInterception info = interception(objets, ray);
            if (info.get_a_atteint() == false) {
                pixels[(i + j * N) * 4] = (int)(fond.get_r() * 255);
				pixels[(i + j * N) * 4 + 1] = (int)(fond.get_g() * 255);
				pixels[(i + j * N) * 4 + 2] = (int)(fond.get_b() * 255);
				pixels[(i + j * N) * 4 + 3] = 255;
            } else {
				Couleur c = couleur_diffusion(info.get_point_interception(), objets, info.get_j(), sources);
                pixels[(i + j * N) * 4] = (int)(c.get_r() * 255);
				pixels[(i + j * N) * 4 + 1] = (int)(c.get_g() * 255);
				pixels[(i + j * N) * 4 + 2] = (int)(c.get_b() * 255);
				pixels[(i + j * N) * 4 + 3] = 255;		
			}
        }
    }
}

void lancer2(Point omega, Couleur fond, sf::Uint8 *pixels, std::vector<Sphere> objets, std::vector<Source> sources) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			Rayon ray = rayon_ecran(omega, i, j);
			Couleur c = couleur_percue(ray, fond, objets, sources);
            pixels[(i + j * N) * 4] = (int)(c.get_r() * 255);
			pixels[(i + j * N) * 4 + 1] = (int)(c.get_g() * 255);
			pixels[(i + j * N) * 4 + 2] = (int)(c.get_b() * 255);
			pixels[(i + j * N) * 4 + 3] = 255;	
		}
	}
}

void lancer3(Point omega, Couleur fond, sf::Uint8 *pixels, std::vector<Sphere> objets) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			Rayon ray = rayon_ecran(omega, i, j);

			Couleur couleur_finale = Couleur(0, 0, 0);

			for (int k=0; k < nray_pixels; k++) {
				couleur_finale += rayon_couleur(ray, objets, fond, i + j * N);
			}

			Couleur couleur_pixel = (1/((double)nray_pixels)) * couleur_finale;
			
			pixels[(i + j * N) * 4] = (int)(couleur_pixel.get_r() * 255);
			pixels[(i + j * N) * 4 + 1] = (int)(couleur_pixel.get_g() * 255);
			pixels[(i + j * N) * 4 + 2] = (int)(couleur_pixel.get_b() * 255);
			pixels[(i + j * N) * 4 + 3] = 255;	
		}
	}
}

void lancer4(Point omega, Couleur fond, sf::Uint8 *pixels, std::vector<Sphere> objets, std::vector<Source> sources) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			Rayon ray = rayon_ecran(omega, i, j);

			Couleur couleur_finale = Couleur(0, 0, 0);

			for (int k=0; k < nray_pixels; k++) {
				couleur_finale += couleur_percue2(ray, fond, objets, sources, i + j * N);
			}

			Couleur couleur_pixel = (1/((double)nray_pixels)) * couleur_finale;
			
			pixels[(i + j * N) * 4] = (int)(couleur_pixel.get_r() * 255);
			pixels[(i + j * N) * 4 + 1] = (int)(couleur_pixel.get_g() * 255);
			pixels[(i + j * N) * 4 + 2] = (int)(couleur_pixel.get_b() * 255);
			pixels[(i + j * N) * 4 + 3] = 255;	
		}
	}
}