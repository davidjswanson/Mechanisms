#include <iostream>

using namespace std;
class Point;

class Relation{
	public:
                Relation(Point*);
	protected:
                Point* target;
                Point* getTarget();
};

Relation::Relation(Point* targetPoint){
	target = targetPoint;
}

Point* Relation::getTarget(){
        return target;
}
