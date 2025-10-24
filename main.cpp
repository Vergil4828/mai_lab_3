#include <iostream>
#include <vector>
#include "include/figure.h"
#include "include/pentagon.h"
#include "include/rhombus.h"
#include "include/trapezoid.h"

int main() {
    int figureCount;
    std::cout<<"Введите количество фигур: ";
    std::cin>>figureCount;
    
    std::vector<Figure*> figures(figureCount);

    for (int i=0;i<figureCount;++i){
        char type;
        std::cout <<"Фигура №"<< i+1 <<". Введите тип фигуры - (P/R/T): ";
        std::cin >> type;

        if (type=='P'){
            std::pair<double, double> c1, c2, c3, c4, c5;
            std::cout <<"Введите кординаты 5 точек в формате x y: ";
            std::cin >>c1.first >>c1.second >>c2.first >>c2.second 
                     >>c3.first >>c3.second >>c4.first >>c4.second 
                     >>c5.first >>c5.second;
            figures[i]=new Pentagon({c1, c2, c3, c4, c5});
        }
        else if (type=='R'){
            std::pair<double, double> c1, c2, c3, c4;
            std::cout << "Введите кординаты 4 точек в формате x y: ";
            std::cin >>c1.first >>c1.second >>c2.first >>c2.second 
                     >>c3.first >>c3.second >>c4.first >>c4.second;
            figures[i]=new Rhombus({c1, c2, c3, c4});
        }
        else if (type=='T'){
            std::pair<double, double> c1, c2, c3, c4;
            std::cout << "Введите кординаты 4 точек в формате x y: ";
            std::cin >>c1.first >>c1.second >>c2.first >>c2.second 
                     >>c3.first >>c3.second >>c4.first >>c4.second;
            figures[i]=new Trapezoid({c1, c2, c3, c4});
        }
        else {
            std::cout << "Неверный тип фигуры\n";
            --i;
        }
    }

    double totalArea = 0;
    std::cout << "\n";
    for (int i=0;i<figureCount;++i){
        std::cout << "Фигура №" <<i+1 << ": "<<figures[i]->figureName()
                  << "\nКоординаты центра: ("<<figures[i]->figureCenter().first 
                  << ", "<<figures[i]->figureCenter().second<<")"
                  << "\nПлощадь: " <<static_cast<double>(*figures[i])<<"\n";
        totalArea += static_cast<double>(*figures[i]);
    }
    std::cout << "Сумма площадей:"<<totalArea<<"\n";
    for (int i=0;i<figureCount;++i){
        delete figures[i];
    }

    return 0;
}