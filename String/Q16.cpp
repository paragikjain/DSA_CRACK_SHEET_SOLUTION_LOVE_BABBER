#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int solution(){
stack<char> st;
      string input;
      cin>>input;
      int n = input.length();
      for(int i=0;i<n;i++)
      {
       if(input[i]=='(' || input[i]=='{' || input[i]=='['){
           st.push(input[i]);
       }
       else if(input[i]==')' || input[i]=='}' || input[i]==']'){
           if(st.empty()){
               cout<<"not balanced"<<endl;
               return 0;
           }
          
           if(st.top() == '(' && input[i] == ')' || 
              st.top() == '{' && input[i] == '}' ||
              st.top() == '[' && input[i] == ']')
           {
             st.pop();  
           }
           else 
           {
               cout<<"not balanced"<<endl;
               return 0; 
           }
       }
      }
      
      if(st.empty()){
       cout<<"balanced"<<endl;
       return 0;           
      }
      else{
        cout<<"not balanced"<<endl;
        return 0;         
      }    
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