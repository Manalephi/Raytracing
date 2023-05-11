#include "Vecteur.hpp"
#include <math.h>

Vecteur::Vecteur(double x, double y, double z) : 
m_x(x), m_y(y), m_z(z)
{

}

double Vecteur::get_x() {
    return m_x;
}

double Vecteur::get_y() {
    return m_y;
}

double Vecteur::get_z() {
    return m_z;
}

Vecteur Vecteur::oppose(){
    return Vecteur(-m_x, -m_y, -m_z);
}

double Vecteur::norme(){
    return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}



double ps(Vecteur v1, Vecteur v2) {
    return v1.get_x() * v2.get_x() + v1.get_y() * v2.get_y() + v1.get_z() * v2.get_z();
}

Vecteur Vecteur::unitaire() {
    double n = this->norme();
    return Vecteur(m_x/n, m_y/n, m_z/n);
}