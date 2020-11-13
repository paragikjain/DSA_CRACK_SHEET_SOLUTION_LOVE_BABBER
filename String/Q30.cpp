#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//this programe is swapping with any charcter not just adjaect
//in excel sheet they have likned question with swapping only with ajeacent charectr
//but if we in adjecnt charcret if we find we have count which counts [  and when we get ] we will
//decrease count when count is less then 0 that means we have extra ] so we will start swapping. and count the swaps


void solution()
{
  int n;
  cin>>n;
  string input;
  cin>>input;
  stack<char> st;
  
  int swaps=0;
  for(int i=0;i<n;i++){
    if(st.empty()){
        st.push(input[i]);
    }
    else
    {
      if(st.top()=='['){
        if(input[i]=='[')
         st.push(input[i]);
        else
         st.pop();
       }
       else{
         if(input[i]==']')
         st.push(input[i]);
         else{
           swaps++;  
           st.pop();  
         }
       }
     }
  }
  
  cout<<swaps<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solution();
        
    }
}