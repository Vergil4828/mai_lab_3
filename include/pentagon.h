#pragma once
#include "figure.h"
#include <vector>
#include <initializer_list>

class Pentagon: public Figure
{
public:
    Pentagon(const std::initializer_list<std::pair<double, double>>& coords);
    std::string figureName() const override;
    std::pair<double,double> figureCenter() const override;
    std::vector<std::pair<double,double>> figureCoord() const override;
    operator double() const override;
    Pentagon* clone() const override;
    bool operator==(const Figure& other) const override;
    bool operator==(const Pentagon& other) const {
        return this->operator==(static_cast<const Figure&>(other));
    }
    void print(std::ostream& os) const override;
    void add(std::istream& is) override;
};