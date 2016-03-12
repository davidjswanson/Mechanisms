/* Coordinate Class
*  Revision History
*  ================
*  2016-03-12	DJS	Initial Issue
*
*/

#include <iostream>

using namespace std;

/* Class Coordinate
*  used for storing 2 dimensional coordinates
*  so they can be easily moved around in a program
*/
class Coordinate{
	public:
		Coordinate() {x=0, y=0;}							// Default to Zero
		Coordinate(double inX, double inY) {x=inX, y=inY;}	// Or specify two numbers
		bool set(char, double);								// Set value for a particular axis
		double get(char);									// Get value for a particular axis
		friend ostream& operator <<(ostream &, const Coordinate&);	//Print the coordinate
	private:
		double x;
		double y;
};

/* Coordinate::set
*  used for setting an indivicual value for a coordinate axis
*  returns 0 on success, 1 on failure to set value.
*/
bool Coordinate::set(char axis, double value){
	switch(axis){
		case 'x':
		case 'X':
			x = value;
		break;
		case 'y':
		case 'Y':
			y = value;
		break;
		default:
			return 1;	
	}
	return 0;
}

/* Coordinate::get
*  used for getting an individual axis value
*/

double Coordinate::get(char axis){
	switch(axis){
		case 'x':
		case 'X':
			return x;
		break;
		case 'y':
		case 'Y':
			return y;
		break;
		default:
			return 0;	
	}
}

ostream& operator <<(ostream &arg1, const Coordinate &arg2)
{	
	arg1 << "(" << arg2.x << ", " << arg2.y << ")";
	return arg1;
}