/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {

    const auto &lhsV = (const std::vector<Point> &) lhs;
    const auto &rhsV = (const std::vector<Point> &) rhs;

    if(lhsV.size() == 0 && rhsV.size() == 0){

        const auto &lhsP = (const Point&) lhs;
        
        return (rhs.contains(lhsP));
    }

    for(const Point& elem : lhsV){

        if( !(rhs.contains(elem)) ){
            return false;
        }
    }

    for(const Point& elem : rhsV){

        if( !(lhs.contains(elem)) ){
            return false;
        }
    }
    
    return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {

    if(this->limits[0].x < this->limits[1].x){

        if(p.x < this->limits[0].x || p.x > this->limits[1].x){

            return false;
        }
    }else{

        if(p.x < this->limits[1].x || p.x > this->limits[0].x){

            return false;
        }
    }

    if(this->limits[0].y < this->limits[1].y){

        if(p.y < this->limits[0].y || p.y > this->limits[1].y){

            return false;
        }
    }else{

        if(p.y < this->limits[1].y || p.y > this->limits[0].y){

            return false;
        }
    }

    return true;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
    
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1){
    
    Point p0(x0,y0);
    Point p1(x1,y1);

    this->limits.push_back(p0);
    this->limits.push_back(p1);

}