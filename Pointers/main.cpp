//I learned pointers in undergad uni (nearly 8 years ago haha) - but some revision never hurts

#include <iostream>

using namespace std;

void changeData(int *x){
    *x = 10;

}

int main() {

    int x = 6;
    changeData(&x);
    //int *y = &x;

    //use dereferncing operator to reference y
    //references always point to the same part of memory whereas the data pointed to can be changed

    //so make new variable z and change y to the reference of z
    //so to chnage value of a pointer use * - to change by reference you do &
   /* int z = 10;
    y = &z;
    
    *y = 60;

    //better to use references over pointers?

    cout << &x << endl;

    cout << x << " " << *y << " " << z << endl; */

    cout << x << endl;

}