#ifndef RENDER_H
#define RENDER_H

#include <cmath>
#include <iostream>
#include "CameraBuff.h"
#include "ray.h"


PixelColor generatedColor(const Ray& r) {
    Vec unit_direction = unit_vector(r.direction());
    //std::cout << r.direction().getY() << std::endl;
    return (abs((int)(r.direction().getY()))*PixelColor(0, 0, 255)); 
    // abs((int)(r.direction().getX()))*
    // abs((int)(r.direction().getY()))
}

//! Splits the m into squares/areas
//! Every square is filled with colors by m.draw() function

void Rendering( CameraBuff &m , int &imageX , int &imageY ){ 

    const auto aspect_ratio = imageX / imageY;

    // Camera

    float viewport_height = imageY;
    float viewport_width = aspect_ratio * viewport_height;

    auto focal_length = 0.0;  //! focal length is the distance between the projection point and the image plane

    Vec origin = Vec(0,0,0);
    Vec horizontal = Vec(viewport_width, 0, 0);
    Vec vertical = Vec(0, viewport_height, 0);
    Vec lower_left_corner = origin - horizontal/2 - vertical/2 - Vec(0, 0, focal_length);
    std::cout << lower_left_corner << std::endl;
    Vec start(0,0,0);                              //! Starts from the left top corner

    //! Starts from the left top corner
    int stepByX = m.imageX/imageX;         // The step by X axis
    int stepByY = m.imageY/imageY;         // The step by Y axis

    Vec end(stepByX,stepByY ,0);              // ending point where the draw functions ends

    //! Iteration true the squares in the image and calling draw() function for every square
    for( int y = 0; y < imageY; y++ ){
            start.setX(0);
            end.setX(stepByX);

            for( int x = 0; x < imageX; x++ ){

                        float v = float(y) / (imageY-1);
                        float u = float(x) / (imageX-1);

                        Vec vec = lower_left_corner + u*horizontal + v*vertical - origin;

                        Ray ray(origin,vec);
                        PixelColor color = generatedColor(ray) ;
                        m.draw(start,end ,color);
                        start.addX(stepByX);
                        end.addX(stepByX);
            }
            start.addY(stepByY);
            end.addY(stepByY);
    }


}

#endif //!RENDER_H