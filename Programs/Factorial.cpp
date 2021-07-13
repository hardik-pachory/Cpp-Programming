#include<iostream>
using namespace std;

int factorial(int num){
    int fact=1;
    while(num>=1){
        fact*=num--;
    }
    return fact;
}

int main(){
    int number;
    cout<<"Enter a testing number : ";
    cin>>number;
    cout<<"Factorial of "<<number<<" is "<<factorial(number);
}