#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float y, H, v, t, a, g = 9.8, x;

    cout<<"Enter H: \t";
    cin>>H;
    cout<<"Enter v: \t";
    cin>>v;
    cout<<"Enter a: \t";
    cin>>a;

    if ((1 + 2*g*H/(pow(v, 2) * pow(sin(a), 2))) >= 0 && sin(a) != 0 && v != 0){
        t = v * sin(a) / g * (1 + sqrt(1 + 2*g*H/(pow(v, 2) * pow(sin(a), 2))));
        x = v * t * cos(a);
        y = H + v*t*sin(a) - g*pow(t, 2) / 2;
    }else{
        return 0;
    }
    
    cout<<"Result x: " << x << endl;
    cout<<"Result y: " << y << endl;

    return 0;
}