#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>


class Figure 
{public:
    // Правило пяти
    Figure()=default;
    Figure(const Figure& other)=default;
    Figure(Figure&& other)=default;
    virtual ~Figure()=default;
    Figure& operator=(const Figure& other)noexcept=default;
    Figure& operator=(Figure&& other)noexcept=default;

    
    virtual std::string figureName() const = 0;
    virtual std::pair<double,double> figureCenter() const =0;
    virtual std::vector<std::pair<double,double>> figureCoord() const=0;
    virtual operator double() const=0;

    virtual Figure*clone() const=0;
    virtual bool operator==(const Figure& other) const=0;

    friend std::ostream&operator<<(std::ostream& output, const Figure& figure){
        figure.print(output);
        return output;
    };
    friend std::istream& operator>>(std::istream& input, Figure& figure){
        figure.add(input);
        return input;
    };

    virtual void print(std::ostream& output) const=0;
    virtual void add(std::istream& input)=0;

protected:
    std::vector<std::pair<double,double>> coords;
};
