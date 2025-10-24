#include "../include/rhombus.h"
#include <vector>
#include <initializer_list>

Rhombus::Rhombus(const std::initializer_list<std::pair<double, double>>& coords) {
    this->coords.assign(coords.begin(), coords.end());
}

std::string Rhombus::figureName() const {
    return "Rhombus";
}
std::pair<double, double> Rhombus::figureCenter() const {
    double x_sum=0, y_sum=0;
    for (const auto& coord:coords){
        x_sum+=coord.first;
        y_sum+=coord.second;
    }
    return {x_sum/4, y_sum/4};
}
std::vector<std::pair<double, double>> Rhombus::figureCoord() const {
    return coords;
}
Rhombus::operator double() const {
    double s=0;
    for (size_t i=0;i<4;++i){
        size_t j=(i+1)%4;
        s+=coords[i].first*coords[j].second - coords[j].first*coords[i].second;
    }
    return std::abs(s)/2;
}
Rhombus* Rhombus::clone() const {
    return new Rhombus(*this);
}

bool Rhombus::operator==(const Figure& other) const {
    if (this->figureName()!= other.figureName()) {
        return false;
    }
    const Rhombus& rhombus = dynamic_cast<const Rhombus&>(other);
    return this->coords == rhombus.coords;
}

void Rhombus::print(std::ostream& output) const {
    output << figureName() << " ";
    for (const auto& coord : coords) {
        output << "(" << coord.first << ", " << coord.second << ") ";
    }
    output << "\n";
}

void Rhombus::add(std::istream& input) {
    coords.clear();
    for (size_t i=0; i < 4; ++i) {
        double x, y;
        input >> x >> y;
        coords.emplace_back(x, y);
    }
}