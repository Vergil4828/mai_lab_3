#include "../include/trapezoid.h"
#include <vector>
#include <initializer_list>

Trapezoid::Trapezoid(const std::initializer_list<std::pair<double, double>>& coords) {
    this -> coords.assign(coords.begin(), coords.end());
}

std::string Trapezoid::figureName() const{
    return "Trapezoid";
}

std::pair<double,double> Trapezoid::figureCenter() const{
    double x_sum=0, y_sum=0;
    for (const auto& coord:coords){
        x_sum+=coord.first;
        y_sum+=coord.second;
    }
    return {x_sum/4, y_sum/4};
}
std::vector<std::pair<double,double>> Trapezoid::figureCoord() const{
    return coords;
}   
Trapezoid::operator double() const{
    double s=0;
    for (size_t i=0;i<4;++i){
        size_t j=(i+1)%4;
        s+=coords[i].first*coords[j].second - coords[j].first*coords[i].second;
    }
    return std::abs(s)/2;
}
Trapezoid* Trapezoid::clone() const{
    return new Trapezoid(*this);
}
bool Trapezoid::operator==(const Figure& other) const{
    if (this->figureName()!= other.figureName()) {
        return false;
    }
    const Trapezoid& trapezoid = dynamic_cast<const Trapezoid&>(other);
    return this->coords == trapezoid.coords;
}
void Trapezoid::print(std::ostream& output) const { 
    output << figureName() << " ";
    for (const auto& coord : coords) {
        output << "(" << coord.first << ", " << coord.second << ") ";
    }
    output << "\n";
}

void Trapezoid::add(std::istream& input) {  
    coords.clear();
    for (size_t i=0; i < 4; ++i) {
        double x, y;
        input >> x >> y;
        coords.emplace_back(x, y);
    }
}