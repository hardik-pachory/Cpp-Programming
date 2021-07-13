#include <iostream>
using namespace std;

int number_sum(int num){
    int sum=0;
    while(num){
        sum = sum+(num%10);
        num /= 10;
    }
    return sum;
}
int main(){
    cout<<number_sum(123);
}