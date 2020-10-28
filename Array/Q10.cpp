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
 int i=0;
 int steps=0;
 while(i<n-1)
 {   
     if(a[i]==0)
     {
         steps=-1;
         break;
     }
     if(a[i]+i>=n-1){
         steps++;
         break;
     }
     //find the max
     int max=-1,short_step=i;
     for(int j=1;j<=a[i];j++)
     {
       if(i+j+a[i+j]>=max){
           short_step=i+j;
           max=i+j+a[i+j];
       }
     }
     //cout<<i<<endl;
     i=short_step;
     steps++;
 }
 cout<<steps<<endl;
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