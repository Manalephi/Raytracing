#ifndef VECTEUR_HPP_INCLUDED
#define VECTEUR_HPP_INCLUDED

#include "Point.hpp"

/* Caractérise les vecteurs dans l'espace par ses coordonnées
x y z */
class Vecteur
{
    public:

    /* Constructeur sur les coordonnées */
    Vecteur(double x, double y, double z);

    /* Constructeur sur les points */
    Vecteur(Point a, Point b);

    /* Assesseurs x */
    double get_x();

    /* Assesseurs y */
    double get_y();

    /* Assesseurs z */
    double get_z();

    /* Renvoie l'oppose du vecteur */
    Vecteur oppose();

    /* Renvoie la norme d'un vecteur */
    double norme();

    /* Renvoie le vecteur unitaire */
    Vecteur unitaire();
    
    /* operateur += sur les vecteurs */
    Vecteur& operator+=(Vecteur v);

    /* operateur *= sur les vecteurs */
    Vecteur operator*=(Vecteur v);

    Vecteur mult_scalaire(double k);

    private:

    double m_x;
    double m_y;
    double m_z;
};

double ps(Vecteur v1, Vecteur v2);

Vecteur operator+(Vecteur v1, Vecteur v2);

Vecteur operator*(Vecteur v1, Vecteur v2);

Vecteur operator*(double k, Vecteur v);

#endif //VECTEUR_HPP_INCLUDED