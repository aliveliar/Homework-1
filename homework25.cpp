#include <iostream>
using namespace std;

int main(){
    int roof, without, garden, floor, water, material;
    float summa = 0;

    cout<<"Square roof: \t";
    cin>>roof;
    cout<<"Square without roof: \t";
    cin>>without;
    cout<<"Square garden: \t";
    cin>>garden;

    summa  = roof * 5 + without *  3 + garden;

    cout<< "Material (qualitative - 1, adobe - 2, others - 3) \t";
    cin>>material;
    if (material == 1){
        summa = summa * 1.15;

    }else if(material == 2){
        summa = summa * 1.1;
    }else{
        summa = summa * 1.05;
    }

    cout << "Base service (0, 1): \t";
    cin>>water;
    if (water == 1){
        summa += 2.5;
    }

    cout << "How many floors: \t";
    cin >> floor;
    if (floor == 2){
        summa = summa * 1.10;
    }else if(floor == 3 || floor == 4){
        summa = summa * 1.15;
    }else{
        summa = summa * 1.2;
    }

    cout <<"Total sum: " << summa << " thousands" << endl;

    return 0;
}