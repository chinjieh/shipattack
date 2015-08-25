#include "IMovable.h"
#include "Brain.h"
#include "Appearance.h"
class Actor : public IMovable{
public:
	Actor();
	~Actor();

	void move();


private:
	Appearance appearance;
	Brain brain;
	

};