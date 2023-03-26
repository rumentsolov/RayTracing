/*
Добавете представяне триъгълник във вашите C++ проекти. Той трябва да е съставен от 3 върха, за всеки, от които може да използвате 3D вектор, реда на върховете е от значение.

Задача 2.
Изчислете векторното произведение(AxB) между двата вектора А = (3.5, 0, 0) и B = (1.75, 3.5, 0)
Изчислете векторното произведение(AxB) между двата вектора А = (3, -3, 1) и B = (4, 9, 3)
Изчислете лицето на успоредника, който се формира с векторите А = (3, -3, 1) и B = (4, 9, 3)
Изчислете лицето на успоредника, който се формира с векторите А = (3, -3, 1) и B = (-12, 12, -4)

Задача 3.
Намерете нормал вектор за триъгълник със следните върхове:
A = (-1.75, -1.75, -3)
B = (1.75, -1.75, -3)
C = (0, 1.75, -3)
Намерете нормал вектор за триъгълник със следните върхове:
A = (0, 0, -1)
B = (1, 0, 1)
C = (-1, 0, 1)
Намерете нормал вектор за триъгълник със следните върхове:
A = (0.56, 1.11, 1.23)
B = (0.44, -2.368, -0.54)
C = (-1.56, 0.15, -1.92)
Изчислете лицата на триъгълниците
 

*/

#include "cameraBuff.h"
#include "vec.h"


int main() {

    CameraBuff buff(900,700 );
    buff.record();
    
	return 0;
}

/*

bool intersect = rayIntersectsTriangle(origin,vec ,a,b,c);

//if(!intersect) {
//str[x][y] = PixelColor( 0 , 0 , 0);
//}
//else{
PixelColor color(
(originX - abs(vec.X()))*colorCoefficient , 
(originY - abs(vec.Y()))*colorCoefficient , 
abs(vec.Z())); 
str[x][y] = color;
//}



 Vec a( 0, 175, -30 ); 
        Vec b( -175, -175, -30 );
        Vec c( 175, -175, -30 );

*/