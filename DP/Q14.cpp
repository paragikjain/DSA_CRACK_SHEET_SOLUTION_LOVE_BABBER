// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence
#define c 1000
#define r 1000
int lcsutil(int a,int b,string s1, string s2,int arr[r][c])
{
        
    if(a >s1.size()-1 || b > s2.size()-1){
        return 0;
    }
    if(arr[a][b] != -1){
        return arr[a][b];
    }

    if(s1[a] == s2[b]){
        arr[a][b] =  1+lcsutil(a+1,b+1,s1,s2,arr);
        return arr[a][b];
    }
    else{
        int x = lcsutil(a,b+1,s1,s2,arr);
        int y = lcsutil(a+1,b,s1,s2,arr);
        arr[a][b] = max(x,y);
        return arr[a][b];
    }
}
int lcs(int x, int y, string s1, string s2){
  int arr[r][c];
  memset(arr,-1,sizeof(arr));
  return lcsutil(0,0,s1,s2,arr);
}
