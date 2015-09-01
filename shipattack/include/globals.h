#ifndef h_globals
#define h_globals


class Vector{
private:
	double _x;
	double _y;

public:
	Vector(){
		_x = 0;
		_y = 0;
	}
	Vector(double x, double y){
		_x = x;
		_y = y;
	}

	~Vector(){}

	double x(void){
		return _x;
	}

	double y(void){
		return _y;
	}

	void setX(double x){
		_x = x;
	}

	void setY(double y){
		_y = y;
	}
};

#endif