#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

/* Représentation du point dans l'espace par ses coordonnées
x y z */
class Point
{
    public:

    /* Constructeur */
    Point(double x, double y, double z);

    private:

    double m_x;
    double m_y;
    double m_z;
};

#endif // POINT_HPP_INCLUDED