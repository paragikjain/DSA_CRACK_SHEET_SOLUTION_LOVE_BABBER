#include<iostream>

using namespace std;

void solution()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
 {
     cin>>a[i];
 }
 int max_till_now=0,curr=0,smallest=-10000000;
 for(int i=0;i<n;i++)
 {
     //for handling negative values. of total is negative then smallest negative finding.
     if(a[i]>smallest){
         smallest=a[i];
     }
     curr=curr+a[i];
     if(max_till_now<curr){
         max_till_now=curr;
     }
     if(curr<0){
         curr=0;
     }
 }
 if(max_till_now==0){
     cout<<smallest;
     cout<<endl;
     return;
 }
 cout<<max_till_now<<endl;
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