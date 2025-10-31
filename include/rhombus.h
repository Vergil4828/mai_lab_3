#pragma once
#include <iostream>
#include "figure.h"
#include <initializer_list>

class Rhombus: public Figure
{
public:
    Rhombus(const std::initializer_list<std::pair<double, double>>& coords);

    std::string figureName() const override;
    std::pair<double,double> figureCenter() const override;
    std::vector<std::pair<double,double>>figureCoord() const override;
    operator double() const override;
    Rhombus*clone() const override;
    bool operator==(const Figure& other) const override;
    bool operator==(const Rhombus& other) const {
        return this->operator==(static_cast<const Figure&>(other));
    }
    void print(std::ostream& os) const override;
    void add(std::istream& is) override;



};
