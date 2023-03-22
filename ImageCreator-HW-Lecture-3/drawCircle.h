#ifndef DRAW_CIRCLE_H
#define DRAW_CIRCLE_H

#include "CameraBuff.h"
#include "randoms.h"
#include "point.h"

#include <cmath>

void drawCircle(CameraBuff &m , int &radius){

    radius -=1;
    PixelColor color = getRandNum();
    Point start((m.imageX /2 ) , (m.imageY /2 ));  // starting point where the m draw functions starts
    Point end((m.imageX /2 ) , (m.imageY /2 ));    // ending point where the m draw functions ends
    Point center((m.imageX /2 ) , (m.imageY /2 )); // Center point is needed to calculate the mirroring
    
    const float maxAngle = 1.570796327; // half of the PI because the circle is mirrored by Y axis

   for (double angle=0; angle<=(maxAngle); angle+=0.001){ // drawing from top->bottom, row by row

        start.setX( center.getX() - radius*sin( angle ));
        start.setY( center.getY() - radius*cos( angle ));

        end.setX( center.getX() + radius*sin( angle ));
        end.setY( center.getY() + radius*cos( angle ));

    m.draw(start,end,color);
   }
}



#endif //!DRAW_CIRCLE_H