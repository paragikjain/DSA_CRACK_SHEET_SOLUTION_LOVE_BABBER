#include <iostream>
using namespace std;

int x_pow(int x,int pow){
  if(pow==1)
    return x;
  return x*x_pow(x,pow-1);

}

int main(){
  int x,pow;
  cin>>x>>pow;
  cout<<x_pow(x,pow);
  return 0;
}