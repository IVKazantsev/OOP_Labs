#include <iostream>
#include <cmath>

class Point {
public:
    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }
private:
    double x, y, z;
};

class Vector {
public:
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    Vector(double x1, double y1, double z1) {
        x = x1;
        y = y1;
        z = z1;
    }

    Vector(Point point1, Point point2) {
        x = point2.getX() - point1.getX();
        y = point2.getY() - point1.getY();
        z = point2.getZ() - point1.getZ();
    }


    Vector vectorAddition(Vector otherVector) {
        return Vector(x + otherVector.x, y + otherVector.y, z + otherVector.z);
    }

    Vector vectorSubtraction(Vector otherVector) {
        return Vector(x - otherVector.x, y - otherVector.y, z - otherVector.z);
    }

    Vector negativeVector() {
        return Vector(-x, -y, -z);
    }

    double length() {
        return sqrt(x * x + y * y + z * z);
    }

    Vector unitVector() {
        double len = length();
        if (len > 0) {
            return Vector(x / len, y / len, z / len);
        }
        else {
            return *this;
        }
    }

    double scalarProduct(Vector otherVector) {
        return x * otherVector.getX() + y * otherVector.getY() + z * otherVector.getZ();
    }

    Vector vectorProduct(Vector otherVector) {
        return Vector(
            y * otherVector.getZ() - z * otherVector.getY(),
            z * otherVector.getX() - x * otherVector.getZ(),
            x * otherVector.getY() - y * otherVector.getX()
        );
    }

    double mixedProduct(Vector otherVector1, Vector otherVector2) {
        return this->scalarProduct(otherVector1.vectorProduct(otherVector2));
    }

    bool isCollinear(Vector otherVector) {
        // Векторы коллинеарны, если их векторное произведение равно нулю
        return this->vectorProduct(otherVector).length() == 0;
    }

    bool isCoplanar(Vector otherVector1, Vector otherVector2) {
        // Три вектора компланарны, если их смешанное произведение равно нулю
        return this->mixedProduct(otherVector1, otherVector2) == 0;
    }

    double angleWith(Vector otherVector) {
        // Угол между векторами
        double scalarProd = scalarProduct(otherVector);
        double len1 = length();
        double len2 = otherVector.length();
        return 57.2958 * acos(scalarProd / (len1 * len2));
    }
private:
    double x, y, z;
};

int main() {
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;

    std::cout << "Введите координаты первой точки: ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "Введите координаты второй точки: ";
    std::cin >> x2 >> y2 >> z2;
    std::cout << "Введите координаты второго вектора: ";
    std::cin >> x3 >> y3 >> z3;
    std::cout << "Введите координаты третьего вектора: ";
    std::cin >> x4 >> y4 >> z4;

    Point point1(x1, y1, z1);
    Point point2(x2, y2, z2);

    Vector vector1(point1, point2);
    Vector vector2(x3, y3, z3);
    Vector vector3(x4, y4, z4);

    std::cout << "Вектор 1: " << vector1.getX() << " " << vector1.getY() << " " << vector1.getZ() << std::endl;
    std::cout << "Вектор 2: " << vector2.getX() << " " << vector2.getY() << " " << vector2.getZ() << std::endl;
    std::cout << "Вектор 3: " << vector3.getX() << " " << vector3.getY() << " " << vector3.getZ() << std::endl;

    Vector sum = vector1.vectorAddition(vector2);
    Vector difference = vector1.vectorSubtraction(vector2);
    Vector negative = vector1.negativeVector();
    Vector unit = vector1.unitVector();
    double scalarProd = vector1.scalarProduct(vector2);
    Vector vectorProd = vector1.vectorProduct(vector2);
    double mixedProd = vector1.mixedProduct(vector2, vector3);
    bool collinear = vector1.isCollinear(vector2);
    bool coplanar = vector1.isCoplanar(vector2, Vector(1, 2, 3));
    double angle = vector1.angleWith(vector2);

    std::cout << "Сложение: " << sum.getX() << " " << sum.getY() << " " << sum.getZ() << std::endl;
    std::cout << "Вычитание: " << difference.getX() << " " << difference.getY() << " " << difference.getZ() << std::endl;
    std::cout << "Обратный вектор: " << negative.getX() << " " << negative.getY() << " " << negative.getZ() << std::endl;
    std::cout << "Единичный вектор: " << unit.getX() << " " << unit.getY() << " " << unit.getZ() << std::endl;
    std::cout << "Скалярное произведение: " << scalarProd << std::endl;
    std::cout << "Векторное произведение: " << vectorProd.getX() << " " << vectorProd.getY() << " " << vectorProd.getZ() << std::endl;
    std::cout << "Смешанное произведение: " << mixedProd << std::endl;
    std::cout << "Коллинеарны: " << (collinear ? "Да" : "Нет") << std::endl;
    std::cout << "Компланарны: " << (coplanar ? "Да" : "Нет") << std::endl;
    std::cout << "Угол между векторами: " << angle << " градусов" << std::endl;

    return 0;
}