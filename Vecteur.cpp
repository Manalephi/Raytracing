#include "Vecteur.hpp"
#include <math.h>

Vecteur::Vecteur(double x, double y, double z) : 
m_x(x), m_y(y), m_z(z)
{

}

Vecteur::Vecteur(Point a, Point b) :
m_x(b.get_x() - a.get_x()), m_y(b.get_y() - a.get_y()), m_z(b.get_z() - a.get_z())
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

Vecteur& Vecteur::operator+=(Vecteur v) {
    m_x += v.get_x();
    m_y += v.get_y();
    m_z += v.get_z();
    return *this;   
}

Vecteur operator+(Vecteur v1, Vecteur v2) {
    Vecteur copie(v1);
    copie += v2;
    return copie;
}

Vecteur Vecteur::operator*=(Vecteur v) {
    m_x *= v.get_x();
    m_y *= v.get_y();
    m_z *= v.get_z();
    return *this;   
}

Vecteur operator*(Vecteur v1, Vecteur v2) {
    Vecteur copie(v1);
    copie *= v2;
    return copie;
}

Vecteur Vecteur::mult_scalaire(double k) {
    return Vecteur(m_x * k, m_y * k, m_z * k);
}

Vecteur operator*(double k, Vecteur v) {
    return v.mult_scalaire(k);
}