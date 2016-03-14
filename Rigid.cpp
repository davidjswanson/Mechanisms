
#define RIGID 1
#include <iostream>

using namespace std;


class Rigid : public Relation {
	public:
                Rigid(Value,Point*);
                Point* getTarget();
                Value getDistance();
	private:
		Value distance;
};

Rigid::Rigid(Value distancein, Point* pointin) : Relation(pointin)
{
	distance = distancein;
        typeID=RIGID;
}

Value Rigid::getDistance(){
	return distance;
}

Point* Rigid::getTarget(){
    return target;
}
