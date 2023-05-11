#ifndef COULEUR_HPP_INCLUDED
#define COULEUR_HPP_INCLUDED

/* Caractérise la couleur par ses composantes r g b */
class Couleur
{
    public:
    /* Constructeur */

    Couleur(double r, double g, double b);

    private:

    double m_r;
    double m_g;
    double m_b;
};

#endif //COULEUR_HPP_INCLUDED