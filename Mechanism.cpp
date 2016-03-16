using namespace std;
class Mechanism{
        public:
                Mechanism(string);
                void addPoint(Point*);
                void addRelation(Relation*);
                int getDOF();
        private:
                std::vector<Point*> points;
                std::vector<Relation*> relations;
                string name;

};

Mechanism::Mechanism(string newName){
    name = newName;
}

void Mechanism::addPoint(Point * newPoint){
    points.push_back(newPoint);
}

void Mechanism::addRelation(Relation * newRelation){
    relations.push_back(newRelation);
    newRelation->getPoint('1')->addRelation(newRelation);
    newRelation->getPoint('2')->addRelation(newRelation);
}

int Mechanism::getDOF(){
    int totalJoints=0;
    int totalLinks = 0;
    for(int i=0;i<points.size();i++){
        if(points[i]->getIsJoint()==1){
            totalJoints++;
            if(points[i]->getHasRelations())
                totalLinks++;
        }
    }
    return 3*totalJoints-2*totalLinks;
}
