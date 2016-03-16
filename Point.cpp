#include <string>
#define RIGID 1
using namespace std;
class Point;
#include <vector>
#include ".\Value.cpp"
#include ".\Coordinate.cpp"
#include ".\Relation.cpp"
#include ".\Rigid.cpp"

/* Class Point
*  
*/

class Point{
	public:
		Point();
                Point(double, double);                            //Construct with no range (SET POINT)
                Point(Value, Value);                   //Construct point with current position and range of x and y (SQUARE)
		bool setName(string);				//Return Name of the Point	
		bool setIsGround (bool);			//Set Grounded Property
                bool setRelation;
                void addRelation(Relation*);
                void rotate(double);
                double get(char);
		
		string getName();					//Return Name of the Point
		Coordinate getInitCoord();			//Return Initial Coordinate of Point	
		bool getIsGround();					//Return Grounded Property
                void moveTo(double,double);
                bool getIsJoint();
                bool getHasRelations();
		
	private:
		string name;	// Identifier of the Point
                bool isJoint;
                Coordinate coord;	//Position
		bool ground;	// Is this link fixed to the coordinate system
		bool coupler;	// Is this point connected to different points
                std::vector<Relation*> Relations;
                bool hasRelations;
};

bool Point::setIsGround(bool grnd){
    ground = grnd;
    isJoint=true;
    hasRelations = true;
}
bool Point::getHasRelations(){
    return hasRelations;
}

bool Point::getIsJoint(){
    return isJoint;
}

void Point::addRelation(Relation* newRelation){
    hasRelations = true;
        Relations.push_back (newRelation);
        if(Relations.size()>1)
            isJoint=1;
}

void Point::rotate(double angle){
    for (int i=0;i<Relations.size();i++){
        Relation * thisRelation = Relations[i];
        if (thisRelation->getTypeID()==RIGID){

                double previousAngle = atan((thisRelation->getPoint('2')->get('y')-coord.get('y'))/(thisRelation->getPoint('2')->get('x')-coord.get('x')));
                if(thisRelation->getPoint(2)->get('x')<0)
                    previousAngle+=M_PI;
                cout << previousAngle<<endl;
                double newX = cos(previousAngle+angle)*thisRelation->getDistance();
                double newY = sin(previousAngle+angle)*thisRelation->getDistance();
                thisRelation->getPoint('1')->moveTo(coord.get('x')+newX,coord.get('y')+newY);
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
        isJoint = 0;

}

Point::Point(Value xin, Value yin){
        coord = Coordinate(xin,yin);
        isJoint = 0;
}


Point::Point(){
        isJoint = 0;
}
