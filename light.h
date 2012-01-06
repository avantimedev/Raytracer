#include "point.h"
#include "color.h"

class Light {
public:
	Light();
	Light(Point &pos, Color &col);
private:
	Point pos;
	Color col;
};
