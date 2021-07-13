// * 
// * *
// *  *
// *   * 
// ******

// This is the program to print the above star pattern

#include<iostream>
using namespace std;
int main(){
    int i, j, k;
    for (i = 1; i <= 5; i++){
        cout << "*";
        for (j =1;j<=i-1;j++){
            if(i == 5){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        if(i!=1){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}