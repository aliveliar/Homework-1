#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, k, A, t, w, f;

    cout << "Enter w: \t";
    cin>>w;
    cout << "Enter k: \t";
    cin>>k;
    cout << "Enter A: \t";
    cin>>A;

    f = asin(1 / k);
    t = (90/2 - f) / w;
    
    x = A * sin(w * t + f);

    cout<<"Result: " << x <<endl;



    return 0;
}