#include <iostream>
#include <cmath>
using namespace std;

struct Point {
     int x;
     int y;
     Point( int X, int Y ): x(X), y(Y) {};
};


int main()
{

    Point Center(20 , 20);
    int radius = 10;
    const double PI = 3.14159;

for (double angle=0; angle<=2*PI; angle+=0.001)//You are using radians so you will have to increase by a very small amount
     //This will have the coordinates  you want to draw a point at

     Point( Center.x + radius*cos( angle ), Center.y + radius*sin( angle ) );

	return 0;
}
