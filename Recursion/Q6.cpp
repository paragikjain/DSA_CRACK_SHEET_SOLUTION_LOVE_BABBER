#include <iostream>
using namespace std;

int total_choclate_from_wrapper(int wrapper,int YouWrapper){
  if(YouWrapper<wrapper){
    return 0;
  }
  int rem=YouWrapper%wrapper;
  int div=YouWrapper/wrapper;
  YouWrapper=div+rem;
  return div+total_choclate_from_wrapper(wrapper,YouWrapper);
  
}

int main(){
  int money,price,wrapper;
  cout<<"Enter Total Money"<<endl;
  cin>>money;
  cout<<"Enter Price of Choclate"<<endl;
  cin>>price;
  cout<<"Enter Wrapper count for new choclate"<<endl;
  cin>>wrapper;
  int choclate=money/price;
  cout<<"You Have :"<<choclate+total_choclate_from_wrapper(wrapper,choclate)<<" Choclates";
  return 0;
}