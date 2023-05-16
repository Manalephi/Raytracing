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
    void set_r();
    /*Change la valeur de vert*/
    void set_v();
    /*Change la valeur de bleu*/
    void set_b();    
    
 
    private:

    double m_r;
    double m_g;
    double m_b;
    
    
};

#endif //COULEUR_HPP_INCLUDED

