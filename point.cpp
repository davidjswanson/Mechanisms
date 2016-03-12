#include <stdlib.h>
#include <math.h>
#include <complex>

using namespace std;

class Point{
	public:
		Point();
		int getpt();	// dummy
	private:
		bool ground;	// Is this link fixed to the coordinate system
		bool coupler;	// Is this point connected to different points
};

Point::Point(){
	
}

int Point::getpt(){
	return 10;
}