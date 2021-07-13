/*
     1
    121
   12321
  1234321
 123454321
*/
#include <iostream>
using namespace std;
int main(){
    int i, j, k;
    for(i=1;i<=5;i++){
        for(j=1;j<=5-i;j++){
            cout<<" ";
        }
        for(k=1;k<=i;k++){
            cout<<k;
        }
        k=i-1;
        for(k;k>=1;k--){
            if(k!=0){
                cout<<k;
            }
        }
        cout<<"\n";
    }
    return 0;
}
