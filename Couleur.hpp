#ifndef COULEUR_HPP_INCLUDED
#define COULEUR_HPP_INCLUDED



/* Caractérise la couleur par ses composantes r g b */
class Couleur
{
    public:
    /* Constructeur */
    Couleur(double r, double g, double b);
 
    /*Renvoie m_r*/
    double get_r();
    /*Renvoie m_g*/
    double get_g();
    /*Renvoie m_b*/
    double get_b();
    /*Change la valeur de rouge*/
    void set_r(double r);
    /*Change la valeur de vert*/
    void set_v(double g);
    /*Change la valeur de bleu*/
    void set_b(double b);    
    
    Couleur operator+=(Couleur v);
    Couleur operator*=(Couleur v);
    Couleur mult_scalaire(double k);
    private:

    double m_r;
    double m_g;
    double m_b;
    
    
};

Couleur operator*(Couleur v1, Couleur v2);
Couleur operator*(double coeff, Couleur c);

#endif //COULEUR_HPP_INCLUDED



