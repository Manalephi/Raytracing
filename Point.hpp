#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

/* Représentation du point dans l'espace par ses coordonnées
x y z */
class Point
{
    public:

    /* Constructeur */
    Point(double x, double y, double z);

    double get_x();

    double get_y();

    double get_z();

    void set_x(double x);

    void set_y(double y);

    void set_z(double z);


    private:

    double m_x;
    double m_y;
    double m_z;
};

#endif // POINT_HPP_INCLUDED