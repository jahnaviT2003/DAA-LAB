#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    float m_1, c_1, m_2, c_2, x_1, y_1, x_2, y_2;
    float intersection_X, intersection_Y;
 
    cin >> m_1 >> c_1 >> m_2 >> c_2;
 
    if( (m_1 - m_2) == 0)
        cout << "Lines are not intersecting\n";
    else
    {
        X = (c_2 - c_1) / (m_1 - m_2);
        Y = m_1 * X + c_1;
        cout << fixed << setprecision(2) << X;
        cout << fixed << setprecision(2) << Y;
    }
}