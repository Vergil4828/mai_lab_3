#include "../include/pentagon.h"
#include <vector>
#include <initializer_list>

Pentagon::Pentagon(const std::initializer_list<std::pair<double, double>>& coords) {
    this->coords.assign(coords.begin(), coords.end());
}
std::string Pentagon::figureName() const {
    return "Pentagon";
}
std::pair<double, double> Pentagon::figureCenter() const {
    double x_sum=0, y_sum=0;
    for (const auto& coord:coords){
        x_sum+=coord.first;
        y_sum+=coord.second;
    }
    return {x_sum/5, y_sum/5};
}
std::vector<std::pair<double, double>> Pentagon::figureCoord() const {
    return coords;
}
Pentagon::operator double() const {
    double s=0;
    for (size_t i=0;i<5;++i){
        size_t j=(i+1)%5;
        s+=coords[i].first*coords[j].second - coords[j].first*coords[i].second;
    }
    return std::abs(s)/2;
}
Pentagon* Pentagon::clone() const {
    return new Pentagon(*this);
}
bool Pentagon::operator==(const Figure& other) const {
    if (this->figureName()!= other.figureName()) {
        return false;
    }
    const Pentagon& pentagon = dynamic_cast<const Pentagon&>(other);
    return this->coords == pentagon.coords;
}
void Pentagon::print(std::ostream& output) const {
    output <<figureName() <<" ";
    for (const auto& coord : coords) {
        output << "(" << coord.first << ", " << coord.second << ") ";
    }
    output << "\n";
}
void Pentagon::add(std::istream& input) {
    coords.clear();
    for (size_t i = 0; i < 5; ++i) {
        double x, y;
        input >> x >> y;
        coords.emplace_back(x, y);
    }
}