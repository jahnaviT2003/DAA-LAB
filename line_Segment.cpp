#include <iostream>
#include <math.h>

void main()

{

    float slope, intercept;
    float x1, y1, x2, y2;
    float px, py;
    float left, top, right, bottom; 
    float dx, dy;

    std::cin >> x1;
    std::cin >> y1;
    std::cin >> x2;
    std::cin >> y2;

    std::cin >> px;
    std::cin >> py;

    dx = x2 - x1;
    dy = y2 - y1;

    slope = dy / dx;

    intercept = y1 - slope * x1; 

    if(x1 < x2)
    {
        left = x1;
        right = x2;
    }

    else
    {
        left = x2;
        right = x1;
    }

    if(y1 < y2)
    {
        top = y1;
        bottom = y2;
    }

    else
    {
        top = y1;
        bottom = y2;
    }

    if( slope * px + intercept > (py - 0.01) && slope * px + intercept < (py + 0.01))
    {
        if( px >= left && px <= right && py >= top && py <= bottom )
        {
            std::cout << "Given point lies in the line segment\n";
        }

        else

            std::cout << "Given point is outside the line segment\n";

 

    }

    else

        std::cout << "The point is outside the line segment\n";

   

}