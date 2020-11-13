#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solution()
{
    int n;
    cin>>n;
    string a[n];
    unordered_map<string,int> umap;
    for(int i=0;i<n;i++){
      cin>>a[i];
      umap[a[i]]++;
    }
    int prev=INT_MIN;
    int curr=INT_MIN;
    
    for(auto x:umap){
       
        if(x.second>curr){
            prev=curr;
            curr=x.second;
        }
        
        if(x.second>prev && x.second!=curr){
            prev=x.second;
        }
        
    }
    
    //regeeting the value of prev using iteration

   for(auto x:umap){
    if(x.second==prev){
      cout<<x.first<<endl;    
      break;
    }
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