/*
    1
   101
  10101
 1010101
101010101
*/
#include <iostream>
using namespace std;
int main(){
    int i, j, k;
    for(i=1;i<=5;i++){
        for(j=1;j<=5-i;j++){
            cout<<" ";
        }
        for(k=1;k<=2*i -1; k++){
            if(k%2==0){
                cout<<"0";
            }else{
                cout<<1;
            }
        }
        cout<<"\n";
    }
}