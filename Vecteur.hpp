#ifndef VECTEUR_HPP_INCLUDED
#define VECTEUR_HPP_INCLUDED

/* Caractérise les vecteurs dans l'espace par ses coordonnées
x y z */
class Vecteur
{
    public:

    /* Constructeur */
    Vecteur(double x, double y, double);

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
    
    
    private:

    double m_x;
    double m_y;
    double m_z;
};

double ps(Vecteur v1, Vecteur v2);


#endif //VECTEUR_HPP_INCLUDED