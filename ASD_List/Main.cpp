#include <iostream>

using namespace std;

const double PI = 3.14159265358979323846;

double Sin(double x, double eps = 1e-12)
{
    int sign = (x < 0) ? -1 : 1; // Приводимо до [0, 2*pi]
    
    x = fmod(fabs(x), 2 * PI); // Приводимо до [0, pi]
    
    if (x > PI) { x -= PI; sign *= -1; }// Приводимо до [0, pi/2]
    
    if (x > PI / 2) x = PI - x;

    double t = x, s = x;
    for (int n = 3; fabs(t) > eps; n += 2)
        s += t = -t * x * x / n / (n - 1);
    return s * sign;
}

int main()
{
    cout << "User sinus: " << Sin(0.5);
    cout << "\nLibraty sinus: " << sin(0.5);
}