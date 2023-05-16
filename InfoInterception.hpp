#ifndef INFOINTERCEPTION_HPP_INCLUDED
#define INFOINTERCEPTION_HPP_INCLUDED

#include "Point.hpp"
#include "Vecteur.hpp"


class InfoInterception
{
    public:

    /*Constructeur*/
    InfoInterception(bool a_atteint, double distance, Point point_interception, Vecteur vecteur_normal, int j);

    /* Constructeur */
    InfoInterception(bool a_atteint);

    /* Assesseur a_atteint */
    bool get_a_atteint();

    /* Asseseur distance */
    double get_distance();

    /* Assesseur point_interception */
    Point get_point_interception();

    /* Vecteur get_vecteur_normal */
    Vecteur get_vecteur_normal();

    /* Setteur a_atteint */
    void set_a_atteint(bool a_atteint);

    /* Setteur distance */
    void set_distance(double distance);

    /* Setteur point_interception */
    void set_point_interception(Point point_interception);

    /* Setteur vecteur_normal */
    void set_vecteur_normal(Vecteur vecteur_normal);

    int get_j();

    void set_j(int j);

    private:

    bool m_a_atteint; // A atteint un objet ?
    double m_distance; // si oui, distance entre origine et intersection
    Point m_point_interception; // point d'intersection
    Vecteur m_vecteur_normal; // vecteur normal à l'intersection
    int m_j; //indice objet atteint
};

#endif //INFOINTERCEPTION_HPP_INCLUDED