#include <string>

using namespace std;
#include <vector>
#include ".\Value.cpp"
#include ".\Coordinate.cpp"
#include ".\Relation.cpp"

/* Class Point
*  
*/

class Point{
	public:
		Point();
                Point(string myName) {name=myName;}
                Point(double, double);                            //Construct with no range (SET POINT)
                Point(Value, Value, Coordinate);                   //Construct point with current position and range of x and y (SQUARE)
                Point(double, double, double,double,double,double);// (current x,y; xrange, yrange)
		bool setName(string);				//Return Name of the Point	
		bool setIsGround (bool);			//Set Grounded Property
                bool setRelation;
                bool addRelation(Relation);
		
		string getName();					//Return Name of the Point
		Coordinate getInitCoord();			//Return Initial Coordinate of Point	
		bool getIsGround();					//Return Grounded Property
		
	private:
		string name;	// Identifier of the Point
                Coordinate pointCoord;	//Position
                Coordinate coordLimit;	//Bounds on possible positions of this point
		bool ground;	// Is this link fixed to the coordinate system
		bool coupler;	// Is this point connected to different points
                std::vector<Relation> Relations;
};

bool Point::setIsGround(bool grnd){
    ground = grnd;
}

bool Point::addRelation(Relation newRelation){
	Relations.push_back (newRelation);
	return 1;
}

Point::Point(double xin, double yin){
	pointCoord = Coordinate(xin,yin);

}

Point::Point(Value xin, Value yin, Coordinate limits){
	pointCoord = Coordinate(xin,yin);
	coordLimit = limits;

}

Point::Point(double xin, double yin, double xmin,double xmax,double ymin,double ymax){
	pointCoord = Coordinate(xin,yin);
	coordLimit = Coordinate(xmin,xmax,ymin,ymax);

}

Point::Point(){
	
}
