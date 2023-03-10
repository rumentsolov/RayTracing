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

    std::string put = getRandNum(); //"000 000 000  "; // "255 255 255  "
    
    const double PI = 3.14159;


    
   for (double angle=0; angle<=(PI); angle+=0.01){ // drawing from top to bottom

    start.setX( center.getX() - radius*sin( angle ));
    start.setY( center.getY() - radius*cos( angle ));

    end.setX( center.getX() + radius*sin( angle ));
    end.setY( center.getY() + radius*cos( angle ));

    circlePoints.insert( end );

    m.draw(put);
   }
}



#endif //!DRAW_CIRCLE_H