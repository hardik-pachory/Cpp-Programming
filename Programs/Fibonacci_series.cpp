// 0 1 1 2 3 5 8 13

#include<iostream>
using namespace std;

void generate_fibo(int term){
    int a=0, b=1, c;
    cout<<a<<" ";
    if(term==1)
        return;
    cout<<b<<" ";
    if (term==2)
        return;
    for(int i=3;i<=term;i++){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}

int main(){
    generate_fibo(10);
    return 0;
}