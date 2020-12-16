#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void search_binary(int a[],int b[],int n, int m, vector<pair<int,int>> &vec){

  for(int i=0;i<n;i++){
   int low = 0;
   int high = m-1;
   while(low<=high){
     int mid = low +((high-low)/2);
     if(b[mid] == a[i]){
       vec.push_back({i,mid});
       break;
     }
     else if(b[mid]<a[i]){
       low = mid+1;
     }
     else{
       high =mid -1;
     }
   }
  }
}
using namespace std;
int main(){
  int n,m;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  cin>>m;
  int b[m];
  for(int i=0;i<m;i++)
    cin>>b[i];
  //find all common element in both array store it in map with pair of both index;
  vector<pair<int,int>> vec;
  search_binary(a,b,n,m,vec);
  int sum =0;
  int k =0,l=0;
  for(const auto& data : vec) {
    int sum_1 =0;
    for(int i=k;i<=data.first;i++){
      sum_1 = sum_1+a[i];
    }
    int sum_2 = 0 ;
    for(int i=l;i<=data.second;i++){
      sum_2 = sum_2+b[i];
    }
    // cout<<sum_1<<" "<<sum_2<<endl;
    if(sum_1>sum_2){
      sum = sum+sum_1;
    }
    else{
      sum = sum+sum_2;
    }
    k=data.first+1;
    l=data.second+1;
  }
  int sum_1 =0;
  while(k<n){
    sum_1=sum_1+a[k];
    k++;
  }
  int sum_2=0;
  while(l<m){
    sum_2=sum_2+b[l];
    l++;
  }
  if(sum_1>sum_2){
    sum = sum+sum_1;
  }
  else{
    sum = sum+sum_2;
  } 
  cout<<sum<<endl;
  return 0;
}