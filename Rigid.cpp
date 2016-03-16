
#define RIGID 1
#include <iostream>

using namespace std;


class Rigid : public Relation {
	public:
                Rigid(Value,Point*,Point*);

                Value getDistance();
	private:
		Value distance;
};

Rigid::Rigid(Value distancein, Point* firstPoint, Point* secondPoint) : Relation(firstPoint,secondPoint)
{
	distance = distancein;
        typeID=RIGID;
}

Value Rigid::getDistance(){
	return distance;
}


