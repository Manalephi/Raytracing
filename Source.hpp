#ifndef SOURCE_HPP_INCLUDED
#define SOURCE_HPP_INCLUDED

#include "Couleur.hpp"
#include "Point.hpp"

class Source
{
    public:
    /* Constructeur */
    Source(Point point, Couleur couleur);
  
    /*Renvoie la couleur de la source*/
    Couleur get_couleur();
    /*Renvoie le point de la source*/
    Point get_point();
    /*Change le point de la source*/
    void set_point(Point point);
    /*Change la couleur de la source*/
    void set_couleur(Couleur couleur);

    private:

    Couleur m_couleur; // couleur de la source lumineuse
    Point m_point; // Point où se situt la source
    
    
};

#endif //SOURCE_HPP_INCLUDED
