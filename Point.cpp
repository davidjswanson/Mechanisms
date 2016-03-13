#include <string>
#define RIGID 1
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
                Point(Value, Value);                   //Construct point with current position and range of x and y (SQUARE)
		bool setName(string);				//Return Name of the Point	
		bool setIsGround (bool);			//Set Grounded Property
                bool setRelation;
                bool addRelation(Relation);
                void rotate(double);
                double get(char);
		
		string getName();					//Return Name of the Point
		Coordinate getInitCoord();			//Return Initial Coordinate of Point	
		bool getIsGround();					//Return Grounded Property
                void moveTo(double,double);
		
	private:
		string name;	// Identifier of the Point
                Coordinate coord;	//Position
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

void Point::rotate(double angle){
    for (int i=0;i<Relations.size();i++){
        Relation thisRelation = Relations<Rigid>[i];    // I want a vector of all subtypes of Relations
        if (thisRelation.getTypeID()==RIGID){           // have to use pointers?
                double previousAngle = atan((thisRelation.getTarget()->get('y')-coord.get('y'))/(thisRelation.getTarget()->get('x')-coord.get('x')));
                double newX = cos(previousAngle+angle)*thisRelation.getDistance();
                double newY = sin(previousAngle+angle)*thisRelation.getDistance();
                thisRelation.getTarget()->moveTo(coord.get('x')+newX,coord.get('y')+newY);
        }
    }
}

double Point::get(char axis){
        switch(axis){
                case 'x':
                case 'X':
                        return coord.get('x');
                break;
                case 'y':
                case 'Y':
                        return coord.get('y');
                break;
                default:
                        return 0;
        }
}

void Point::moveTo(double newX, double newY){
    coord.set('x',newX);
    coord.set('y',newY);
}

Point::Point(double xin, double yin){
        coord = Coordinate(xin,yin);

}

Point::Point(Value xin, Value yin){
        coord = Coordinate(xin,yin);

}


Point::Point(){
	
}
