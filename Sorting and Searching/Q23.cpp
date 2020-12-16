#include<iostream>

using namespace std;

void solution()
{
  int n,m,k;
  cin>>n>>m>>k;
  int a[n],b[m];
  for(int i=0;i<n;i++)
   cin>>a[i];
  for(int i=0;i<m;i++)
   cin>>b[i];
   int out;
   int i=0,j=0;
   while(k >0 && i<n && j<m){
       if(a[i]<b[j]){
         out=a[i];
        //  cout<<"i "<<i<<" "<<out<<endl;
         i++;
       }
       else{
         out=b[j];
        //  cout<<"j "<<j<<" "<<out<<endl;
         j++;
        }
        k--;
    
   }
   while(i<n && k >0){
        out=a[i];
        // cout<<i<<" "<<out<<endl;
        i++;
        k--;
   }
   while(j<m && k >0 ){
        out=b[j];
        // cout<<j<<" "<<out<<endl;
        j++;
        k--;
   }
   cout<<out<<endl;
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