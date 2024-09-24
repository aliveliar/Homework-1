#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float sale, money, i, n, vc, moneys;
    char category, client, payment;

    cout<<"Enter money: \t";
    cin>>money;
    cout<<"Which category you want? (A, B, C): \t";
    cin>>category;
    cout<<"What the type of client are you? (P, G, M, B): \t";
    cin>>client;

    moneys = money;

    switch(client){
        case 'P':
            switch (category){
                case 'A': 
                    sale = 0.6;
                    break;
                case 'B': 
                    sale = 0.7;
                    break;
                case 'C': 
                    sale = 0.8;
                    break;
                default:
                    cout<<"Value is wrong"<<endl;
                    return 0;
            }
            break;
        case 'G':
            switch (category){
                case 'A':
                    sale = 0.7; 
                    break;
                case 'B': 
                    sale = 0.8; 
                    break;
                case 'C': 
                    sale = 0.9; 
                    break;
                default: 
                    cout<<"Value is wrong"<<endl;
                    return 0;
            }
            break;
        case 'M':
            switch (category){
                case 'A':
                    sale = 0.8;
                    break;
                case 'B':
                    sale = 0.9;
                    break;
                case 'C':
                    sale = 1;
                    break;
                default:
                    cout<<"Value is wrong"<<endl;
                    return 0;

            }
            break;
        case 'B':
            switch (category){
                case 'A':
                    sale = 1;
                    break;
                case 'B':
                    sale = 1.05;
                    break;
                case 'C':
                    sale = 1.1;
                    break;
                default: 
                    cout<<"Value is wrong"<<endl;
                    return 0;
            }
            break;
        default: 
            cout<<"Value is wrong"<<endl;

            return 0;
    }

    if (client == 'P' || client == 'G'){
        cout<<"What do you want to use to pay? (C - cash, B - bank card, A - credit): \t";
        cin>>payment;
        if (payment == 'C'){
            money = money * sale;
        }else if(payment == 'B'){
            cout<<"Enter the interest rate (3 - 15): \t";
            cin>>i;
            cout<<"Enter the number of contributions: \t";
            cin>>n;
            money = money * (1 + i*n/100); 
            money = money * sale;
        }else if (payment == 'A'){
            cout<<"Enter type of credit (5 - platinum, 2 - business): \t";
            cin>>i;
            cout<<"Enter the number of contributions: \t";
            cin>>n;
            money = money * sale * pow(1 + i/100, n);
        }else{
            cout<<"Wrong payment";
            return 0;
        }
    }else if (client == 'M'){
        cout<<"What do you want to use to pay? (C - cash, B - bank card): \t";
        cin>>payment;
        if (payment == 'C'){
            money = money * sale;
        }else if(payment == 'B'){
            cout<<"Enter the interest rate (3 - 15): \t";
            cin>>i;
            cout<<"Enter the number of contributions: \t";
            cin>>n;
            money = money * (1 + i*n/100); 
            money = money * sale;
        }else{
            cout<<"Wrong payment";
            return 0;
        }
    }else if(client == 'B'){
            money = money * sale;
    }else{
        cout<<"Wrong type of client";
        return 0;
    }

    cout<<"Price: \t"<<moneys<<endl;
    cout<<"Result: \t"<<money<<endl;
    
    return 0;
    }