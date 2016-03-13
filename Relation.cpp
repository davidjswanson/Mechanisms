#include <iostream>

using namespace std;
class Point;

class Relation{
	public:
                Relation(Point*);
                int getTypeID();
	protected:
                Point* target;
                Point* getTarget();
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
