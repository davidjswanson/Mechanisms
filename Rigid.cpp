

#include <iostream>

using namespace std;


class Rigid : public Relation {
	public:
                Rigid(Value,Point);
		Value getDistance();		
	private:
		Value distance;
};

Rigid::Rigid(Value distancein, Point pointin) : Relation(pointin)
{
	distance = distancein;
}

Value Rigid::getDistance(){
	return distance;
}
