#include <iostream>
#include <math.h>
using namespace std;

int is_armstrong(int num){
    if( (pow((num%10),3) + pow(((num/10)%10),3) + pow((num/100),3)) == num ){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    if(is_armstrong(371)){
        cout<<"Armstrong";
    }else{
        cout<<"Not an Armstrong";
    }
    return 0;
}