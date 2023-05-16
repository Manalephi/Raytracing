#include "InfoInterception.hpp"

InfoInterception::InfoInterception(bool a_atteint, double distance, Point point_interception, Vecteur vecteur_normal, int j) :
m_a_atteint(a_atteint), m_distance(distance), m_point_interception(point_interception), m_vecteur_normal(vecteur_normal), m_j(j)
{
    
}

InfoInterception::InfoInterception(bool a_atteint) :
m_a_atteint(a_atteint), m_distance(0), m_point_interception(Point(0, 0, 0)), m_vecteur_normal(Vecteur(0, 0, 0)), m_j(0)
{

}

bool InfoInterception::get_a_atteint() {
    return m_a_atteint;
}



double InfoInterception::get_distance() {
    return m_distance;
}

Point InfoInterception::get_point_interception() {
    return m_point_interception;
}

Vecteur InfoInterception::get_vecteur_normal() {
    return m_vecteur_normal;
}

void InfoInterception::set_a_atteint(bool a_atteint) {
    m_a_atteint = a_atteint;
}

void InfoInterception::set_distance(double distance) {
    m_distance = distance;
}

void InfoInterception::set_point_interception(Point point_interception) {
    m_point_interception = point_interception;
}

void InfoInterception::set_vecteur_normal(Vecteur vecteur_normal) {
    m_vecteur_normal = vecteur_normal;
}

int InfoInterception::get_j() {
    return m_j;
}

void InfoInterception::set_j(int j) {
    m_j = j;
}

