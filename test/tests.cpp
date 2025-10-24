#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/pentagon.h"
#include "../include/rhombus.h"
#include "../include/trapezoid.h"
#include <sstream>

TEST(PentagonTest, GeometricCenter) {
    // Проверка вычисления геометрического центра пятиугольника
    Pentagon pentagon({{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}, {1.5, -1.0}, {0.5, -1.0}});
    auto center = pentagon.figureCenter();
    EXPECT_EQ(center.first,1.0);
    EXPECT_EQ(center.second, -0.2);
}

TEST(PentagonTest, Area) {
    // Проверка вычисления площади пятиугольника
    Pentagon pentagon({{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}, {1.5, -1.0}, {0.5, -1.0}});
    double area= static_cast<double>(pentagon);
    EXPECT_EQ(area, 2.5); 
}

TEST(PentagonTest, Vertices) {
    // Проверка получения координат вершин пятиугольника
    Pentagon pentagon({{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}, {1.5, -1.0}, {0.5, -1.0}});
    auto vertices = pentagon.figureCoord();
    ASSERT_EQ(vertices.size(), 5);
    EXPECT_EQ(vertices[0],std::make_pair(0.0, 0.0));
    EXPECT_EQ(vertices[1],std::make_pair(1.0, 1.0));
    EXPECT_EQ(vertices[2],std::make_pair(2.0, 0.0));
    EXPECT_EQ(vertices[3],std::make_pair(1.5, -1.0));
    EXPECT_EQ(vertices[4],std::make_pair(0.5, -1.0));
}

TEST(PentagonTest, Equality) {
    // Проверка сравнения пятиугольников
    Pentagon pentagon1({{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}, {1.5, -1.0}, {0.5, -1.0}});
    Pentagon pentagon2({{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}, {1.5, -1.0}, {0.5, -1.0}});
    EXPECT_TRUE(pentagon1==pentagon2);
    Pentagon pentagon3({{0.1, 0.1}, {1.0, 1.0}, {2.0, 0.0}, {1.5, -1.0}, {0.5, -1.0}});
    EXPECT_FALSE(pentagon1==pentagon3);
}


TEST(PentagonTest, Clone) {
    // Проверка клонирования пятиугольника
    Pentagon pentagon({{0.0, 0.0}, {1.0, 1.0}, {2.0, 0.0}, {1.5, -1.0}, {0.5, -1.0}});
    Pentagon* cloned =pentagon.clone();
    EXPECT_TRUE(pentagon ==*cloned);
    delete cloned;
}

TEST(RhombusTest, GeometricCenter) {
    // Проверка вычисления геометрического центра ромба
    Rhombus rhombus({{0.0, 0.0}, {2.0, 2.0}, {0.0, 4.0}, {-2.0, 2.0}});
    auto center =rhombus.figureCenter();
    EXPECT_EQ(center.first,0.0);
    EXPECT_EQ(center.second,2.0);
}

TEST(RhombusTest, Area) {
    // Проверка вычисления площади ромба
    Rhombus rhombus({{0.0, 0.0}, {2.0, 2.0}, {0.0, 4.0}, {-2.0, 2.0}});
    double area =static_cast<double>(rhombus);
    EXPECT_EQ(area, 8.0);
}

TEST(RhombusTest, Vertices) {
    // Проверка получения координат вершин ромба
    Rhombus rhombus({{0.0, 0.0}, {2.0, 2.0}, {0.0, 4.0}, {-2.0, 2.0}});
    auto vertices = rhombus.figureCoord();
    ASSERT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], std::make_pair(0.0, 0.0));
    EXPECT_EQ(vertices[1], std::make_pair(2.0, 2.0));
    EXPECT_EQ(vertices[2], std::make_pair(0.0, 4.0));
    EXPECT_EQ(vertices[3], std::make_pair(-2.0, 2.0));
}

TEST(RhombusTest, Equality) {
    // Проверка сравнения ромбов
    Rhombus rhombus1({{0.0, 0.0}, {2.0, 2.0}, {0.0, 4.0}, {-2.0, 2.0}});
    Rhombus rhombus2({{0.0, 0.0}, {2.0, 2.0}, {0.0, 4.0}, {-2.0, 2.0}});
    EXPECT_TRUE(rhombus1 == rhombus2);
    Rhombus rhombus3({{-0.1, 0.1}, {2.0, 2.0}, {0.0, 4.0}, {-2.0, 2.0}});
    EXPECT_FALSE(rhombus1==rhombus3);
}


TEST(RhombusTest, Clone) {
    // Проверка клонирования ромба
    Rhombus rhombus({{0.0, 0.0}, {2.0, 2.0}, {0.0, 4.0}, {-2.0, 2.0}});
    Rhombus* cloned=rhombus.clone();
    EXPECT_TRUE(rhombus==*cloned);
    delete cloned;
}

TEST(TrapezoidTest, GeometricCenter) {
    // Проверка вычисления геометрического центра трапеции
    Trapezoid trapezoid({{0.0, 0.0}, {4.0, 0.0}, {6.0, 4.0}, {2.0, 4.0}});
    auto center=trapezoid.figureCenter();
    EXPECT_EQ(center.first, 3.0);
    EXPECT_EQ(center.second, 2.0);
}

TEST(TrapezoidTest, Area) {
    // Проверка вычисления площади трапеции
    Trapezoid trapezoid({{0.0, 0.0}, {4.0, 0.0}, {6.0, 4.0}, {2.0, 4.0}});
    double area= static_cast<double>(trapezoid);
    EXPECT_EQ(area,16.0);
}

TEST(TrapezoidTest, Vertices) {
    // Проверка получения координат вершин трапеции
    Trapezoid trapezoid({{0.0, 0.0}, {4.0, 0.0}, {6.0, 4.0}, {2.0, 4.0}});
    auto vertices = trapezoid.figureCoord();
    ASSERT_EQ(vertices.size(), 4);
    EXPECT_EQ(vertices[0], std::make_pair(0.0, 0.0));
    EXPECT_EQ(vertices[1], std::make_pair(4.0, 0.0));
    EXPECT_EQ(vertices[2], std::make_pair(6.0, 4.0));
    EXPECT_EQ(vertices[3], std::make_pair(2.0, 4.0));
}

TEST(TrapezoidTest, Equality) {
    // Проверка сравнения трапеций
    Trapezoid trapezoid1({{0.0, 0.0}, {4.0, 0.0}, {6.0, 4.0}, {2.0, 4.0}});
    Trapezoid trapezoid2({{0.0, 0.0}, {4.0, 0.0}, {6.0, 4.0}, {2.0, 4.0}});
    EXPECT_TRUE(trapezoid1 ==trapezoid2);
    Trapezoid trapezoid3({{0.1, 0.1}, {4.0, 0.0}, {6.0, 4.0}, {2.0, 4.0}});
    EXPECT_FALSE(trapezoid1 ==trapezoid3);
}


TEST(TrapezoidTest, Clone) {
    // Проверка клонирования трапеции
    Trapezoid trapezoid({{0.0, 0.0}, {4.0, 0.0}, {6.0, 4.0}, {2.0, 4.0}});
    Trapezoid* cloned = trapezoid.clone();
    EXPECT_TRUE(trapezoid == *cloned);
    delete cloned;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}