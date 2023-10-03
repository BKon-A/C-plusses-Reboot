#include <iostream>

// Створення класу Хрест
class Cross
{
    // Оголошення полів класу, які мають модифікатор доступу private
    int CoordinateA;
    int CoordinateB;
    float CrossSquare;

// Створення методів класу з модифікатором public
public:
    // Створення констуктора класу без параметрів
    Cross()
    {
        CoordinateA = 0;
        CoordinateB = 0;
    }
    // Створення конструктора класу з параметрами
    Cross(int coordinateA, int coordinateB)
    {
        CoordinateA = coordinateA;
        CoordinateB = coordinateB;
    }
    // Метод що обраховує площу 
    void CalculateSquare()
    {
        CrossSquare = (CoordinateA * CoordinateB) * 4 + CoordinateB * 4;
    }
    int GetCoordinateA()
    {
        return CoordinateA;
    }
    int GetCoordinateB()
    {
        return CoordinateB;
    }
    void SetCoordinateA(int coordinateA)
    {
        CoordinateA = coordinateA;
    }
    void SetCoordinateB(int coordinateB)
    {
        CoordinateB = coordinateB;
    }
    // Метод Print_sqrt виводить в консоль значення площі
    void Print_sqrt()
    {
        std::cout << "Square: " << CrossSquare << std::endl;
    }
};

    void main()
    {
        // Створення екщамплярів класу Cross
        Cross defoultCross, cross(12, 5);

        // Встановдення своїх значень з допомогою сеттерів
        defoultCross.SetCoordinateA(7);
        defoultCross.SetCoordinateB(3);

        // Обчислення плоці 
        defoultCross.CalculateSquare();
        cross.CalculateSquare();
        
        // Вивід площі екземплярів в консоль
        defoultCross.Print_sqrt();
        cross.Print_sqrt();
    }