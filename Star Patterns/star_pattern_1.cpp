// *
// **
// ***
// ****
// *****

// This is the program to print the above star pattern.

#include<iostream>
using namespace std;
int main(){
    int i, j;
    for (i = 1; i <= 5; i++){
        for (j = 1; j <= i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}