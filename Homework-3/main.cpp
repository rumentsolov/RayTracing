

/*
Генерирайте картинка, в която всеки пиксел да е оцветен спрямо нормализираната посока на лъча изстрелян към/през него. Експериментирайте с различни резолюции и aspect ratio
Приемете че:
Координатната система, в която работите е Right handed с ос Y сочеща на горе
Позицията на камерата е в (0, 0, 0) (“световния” origin), от където трябва да започват лъчите
Камерата гледа в посока -Z
Image plane-a с пиксели, към/през които трябва да изстрелвате лъчи e със Z координата равна на -1, т.е. на разстояние 1 от/пред камерата

Пример:
Ако за пиксел, който се намира в края на първи ред от картинката (pixels[0][width - 1]) сте генерирали лъч с нормализирана посока rayDir = CRTVector(0.9, 0.8, -0.98) може да запишите неговия цвят като pixels[0][width - 1] = CRTColor(rayDir.x * 255, rayDir.y * 255, ?), решете как да използвате отрицателните стойности като цветови компоненти. 

Псевдо код за алгоритъм за генериране на камера/първични лъчи:
Loop over the image resolution
For x : width; y : height
At each pixel
Find its center, based on the raster coordinates
x += 0.5; y += 0.5
Convert raster coordinates to NDC space [0.0, 1.0]
x /= width; y /= height
Convert NDC coordinates to Screen space [-1.0, 1.0]
x = (2.0 * x) - 1.0
y = 1.0 - (2.0 * y)
Consider the aspect ratio
x *= width / height
Ray direction = (x, y, -1.0)
Normalaize ray direction vector
Store the ray with the calculated direction and originx 

*/

#include "CameraBuff.h"

int main() {


    CameraBuff buff(600,600 );
    buff.record();

	return 0;
}