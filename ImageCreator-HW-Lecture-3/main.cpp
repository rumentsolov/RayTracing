#include "CameraBuff.h"
#include "rendering.h"
#include "coordinates.h"

int main() {


    CameraBuff buff(getImageX(),getImageY() );
    buff.record();

	return 0;
}