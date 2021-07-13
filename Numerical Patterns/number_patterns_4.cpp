// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15

// This is the program to print the above numerical pattern.

#include <iostream>
using namespace std;
int main(){
    int i,j,k =1;
    for(i=1;i<=4;i++){
        for(j=i;j>=1;j--){
            cout<<k++<<" ";
        }
        cout<<"\n";
    }
}