#include <iostream>
using namespace std;


int reverse_number(int number){
    int reversed_num=0;
    while(number!=0){
        reversed_num = (reversed_num * 10) + (number % 10);
        number /= 10;
    }
    return reversed_num;
}


int main(){
    int num;
    cout<<"Enter a test number : ";
    cin>>num;
    // reverse_number = reverse_number(num);
    if(num == reverse_number(num)){
        cout<<"Pallindrome Number";
    }else{
        cout<<"Not a Pallindrome Number.";
    }
}