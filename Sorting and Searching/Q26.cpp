#include <iostream>
typedef long long ll;
using namespace std;

bool isvalid(ll a[],ll n,ll w,ll mid){
  ll total = 0;
  
  for(ll i=0;i<n;i++){
     total = total+(a[i]-mid>0?a[i]-mid:0);
     if(total>=w){
       return true;
     }
  }
  return false;
}
int main(){
  ll n,w;
  cin>>n>>w;
  ll a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  ll low  = a[0];
  ll high = a[0];
  ll out;
  for(int i=1;i<n;i++){
    if(a[i]<low){
      low = a[i];
    }
    if(a[i] >high){
      high = a[i];
    }
  }

  while(low <= high){
    ll mid = low + ((high-low)/2);
    if(isvalid(a,n,w,mid)){
      out = mid;
      low = mid+1;
    }
    else{
      high =mid-1;
    }
  }  
  cout<<out<<endl;
  return 0;
}