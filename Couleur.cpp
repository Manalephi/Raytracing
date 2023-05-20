#include "Couleur.hpp"

Couleur::Couleur(double r, double g, double b) : 
m_r(r), m_g(g), m_b(b)
{

}




double Couleur::get_r(){
	return m_r;
}
/*Renvoie m_g*/
double Couleur::get_g(){return m_g;}
/*Renvoie m_b*/
double Couleur::get_b(){return m_b;}
/*Change la valeur de rouge*/
void Couleur::set_r(double r){m_r = r;}
/*Change la valeur de vert*/
void Couleur::set_v(double g){m_g = g;}
/*Change la valeur de bleu*/
void Couleur::set_b(double b){m_b = b;}
    

Couleur Couleur::operator+=(Couleur v) {
    m_r += v.get_r();
    m_g += v.get_g();
    m_b += v.get_b();
    return *this;   
}

Couleur Couleur::mult_scalaire(double k) {
    return Couleur(m_r * k, m_g * k, m_b * k);
}

Couleur Couleur::operator*=(Couleur v){
	m_r *= v.get_r();
	m_g *= v.get_g();
	m_b *= v.get_b();
	return *this;
}

        
Couleur operator*(Couleur v1, Couleur v2) {
    Couleur copie(v1);
    copie *= v2;
    return copie;
}        
        
Couleur operator*(double coeff, Couleur c) {
    return c.mult_scalaire(coeff);
}
        
        
