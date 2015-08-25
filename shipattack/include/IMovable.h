#include "globals.h"
class IMovable {
public:
	virtual void move() = 0;

private:
	Vector vel = Vector();
};