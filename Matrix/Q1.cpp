#include<iostream>
using namespace std;


    

void solution()
{   
    long long n,i,j,k,l,m;
    cin>>m>>n;
       long long a[m][n];
       for(i=0;i<m;i++)
       {
           for(j=0;j<n;j++)
           {
               cin>>a[i][j];
           }
       }
       k=0,l=0;
       while(k<m && l<n)
       {
           for(i=l;i<n;i++)
           {
               cout<<a[k][i]<<" ";
           }
           k++;
           for(i=k;i<m;i++)
           {
               cout<<a[i][n-1]<<" ";
           }
           n--;
           if(k<m)
           {
               for(i=n-1;i>=l;i--)
               {
                   cout<<a[m-1][i]<<" ";
               }
               m--;
           }
           if(l<n)
           {
                for(i=m-1;i>=k;i--)
               {
                   cout<<a[i][l]<<" ";
               }
               l++;
           }
       }
       cout<<"\n";
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

