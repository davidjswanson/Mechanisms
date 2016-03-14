#include <iostream>

using namespace std;
class Point;

class Relation{
	public:
                Relation(Point*);
                int getTypeID();
                Point* getTarget();
                virtual Value getDistance() =0;
	protected:
                Point* target;
                int typeID;
};

Relation::Relation(Point* targetPoint){
	target = targetPoint;
}

Point* Relation::getTarget(){
        return target;
}

int Relation::getTypeID(){
    return typeID;
}
