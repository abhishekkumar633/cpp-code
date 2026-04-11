#include<iostream>
using namespace std;
bool IsPrime(int i){
    int count=0;
    for(int j=1;j<=i;j++){
        if(i%j == 0){
            count++;
        }
      
    }
      if(count==2){
            return true;
        }else{
                return false;
        }
    
}
int main(){
    for(int i=10;i<100;i++){
        if(IsPrime(i)){
            cout<<i<<" ";
        }
    }
}