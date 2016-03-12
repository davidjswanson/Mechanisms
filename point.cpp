#include <string>

using namespace std;

#include "./Coordinate.cpp"

/* Class Point
*  
*/

class Point{
	public:
		Point();
		Point(string myName) {name=myName;}	
		bool setName(string);				//Return Name of the Point
		bool setInitCoord(coordinate);		//Return Initial Coordinate of Point	
		bool setIsGround (bool);			//Set Grounded Property
		bool setRelation
		
		string getName();					//Return Name of the Point
		Coordinate getInitCoord();			//Return Initial Coordinate of Point	
		bool getIsGround();					//Return Grounded Property
		
	private:
		string name;	// Identifier of the Point
		Coordinate pointCoord	//Position
		bool ground;	// Is this link fixed to the coordinate system
		bool coupler;	// Is this point connected to different points
};

Point::Point(){
	
}
