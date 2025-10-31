#pragma once
#include "figure.h"
#include <vector>
#include <initializer_list>

class Trapezoid: public Figure
{
public:
    Trapezoid(const std::initializer_list<std::pair<double, double>>& coords);

    std::string figureName() const override;
    std::pair<double,double> figureCenter() const override;
    std::vector<std::pair<double,double>> figureCoord() const override;
    operator double() const override;
    Trapezoid* clone() const override;
    bool operator==(const Figure& other) const override;
    bool operator==(const Trapezoid& other) const {
        return this->operator==(static_cast<const Figure&>(other));
    }
    void print(std::ostream& output) const override;
    void add(std::istream& input) override;






};
