#ifndef DRAW_CIRCLE_H
#define DRAW_CIRCLE_H

#include "publics.h"
#include "matrix.h"
#include <set>

void drawCircle(Matrix &m){

    std::set<Point> circlePoints;

    radius -=1;

    Point center((imageX /2 ) , (imageY /2 ));

    start.setX(imageX/2);
    start.setY(imageY/2);

    std::string put = "255 255 255  "; // "255 255 255  "
    
    const double PI = 3.14159;

    //m.draw(put);

    //double angle=0.785 ;
    
   for (double angle=0; angle<=2*PI; angle+=0.001){

       // end.setX( center.getX() + radius*sin( angle ));
        //end.setY( center.getY() + radius*cos( angle ));
        
        circlePoints.insert( end );
   }
       // m.draw(put);

    for(auto i : circlePoints){
        std::cout << i.getX() << ":"<< i.getY() << std::endl;
    }
}



#endif //!DRAW_CIRCLE_H