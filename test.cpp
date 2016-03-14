#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

#include "./Point.cpp"

int main(){
        Point a(0,0);
        Point b(3,4);
        Rigid relA(5,&b);
        Rigid relB(5,&a);
        a.addRelation(&relA);
        b.addRelation(&relB);
        a.rotate(M_PI);
        cout <<b.get('x');
        cout << b.get('y');
	int input;

	cin >> input;
        cout << input;
        cin>>input;
}
