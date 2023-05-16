#include "Point.hpp"

Point::Point(double x, double y, double z) : 
m_x(x), m_y(y), m_z(z)
{
    
}

double Point::get_x() {
    return m_x;
}

void Point::set_x(double x) {
    m_x = x;
}

double Point::get_y() {
    return m_y;
}

void Point::set_y(double y) {
    m_y = y;
}

double Point::get_z() {
    return m_z;
}

void Point::set_z(double z) {
    m_z = z;
}
