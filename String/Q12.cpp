#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  string input;
  cin>>input;
  int count_zero=0,count_one=0,split_count=0;
  for(int i=0;i<input.length();i++){
    if(input[i]=='0'){
      count_zero++;
    }
    else if(input[i]=='1'){
      count_one++;
    }
    else{
      cout<<"invalid string";
      return 0;
    }
    if(count_one==count_zero){
      split_count++;
    }
  }

  cout<<split_count;
  return 0;
}