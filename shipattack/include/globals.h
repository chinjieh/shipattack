#ifndef h_globals
#define h_globals

#include <boost/format.hpp>


class Vector{
public:
	double x, y;

	Vector(){
		x = 0;
		y = 0;
	}
	Vector(double x_attr, double y_attr){
		x = x_attr;
		y = y_attr;
	}

	~Vector(){}

	double getX(void){
		return x;
	}

	double getY(void){
		return y;
	}

	void setX(double x_attr){
		x = x_attr;
	}

	void setY(double y_attr){
		y = y_attr;
	}
};

#endif