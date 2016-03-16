#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

#include "./Point.cpp"
#include "./Mechanism.cpp"

int main(){
        Point a(0,0);
        a.setIsGround(true);
        Point b(-3,-4);
        Point c(3,4);
        Rigid relA(5,&b,&a);
        Rigid relB(10,&c,&a);
        Mechanism newMechanism("test");
        newMechanism.addPoint(&a);
        newMechanism.addPoint(&c);
        newMechanism.addPoint(&b);
        newMechanism.addRelation(&relA);
        newMechanism.addRelation(&relB);
        //a.rotate(M_PI/2);
        cout <<newMechanism.getDOF();

        int input;
        cin >>  input;
        cout<<input;
}
