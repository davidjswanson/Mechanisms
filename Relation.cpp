#include <iostream>

using namespace std;

class Relation{
	public:
                Relation(Point*,Point*);
                int getTypeID();
                Point* getPoint(char);
                virtual Value getDistance() =0;
	protected:
                Point* point1;
                Point* point2;
                int typeID;
};

Relation::Relation(Point* firstPoint,Point* secondPoint){
        point1 = firstPoint;
        point2 = secondPoint;
}

Point* Relation::getPoint(char thisPoint){

    switch(thisPoint){

            case '1':
                    return point1;
            break;

            case '2':
                    return point2;
            break;
            default:
                    return point1;
    }

        return point1;
}

int Relation::getTypeID(){
    return typeID;
}
