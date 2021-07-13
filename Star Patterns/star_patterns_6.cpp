// *       *
//  *     *
//   *   *
//    * *
//     *

// This is the program to print the above star pattern

#include<iostream>
using namespace std;
int main(){
    int i, j, k;
    for (i = 5; i >= 1; i--){
        for(j=1; j<=5-i; j++){
            cout<<" ";
        }
        cout<<"*";
        
        for(k=2*(i-1)-1; k >= 1;k--){
            cout<<" ";
        }
        if(i!=1){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}