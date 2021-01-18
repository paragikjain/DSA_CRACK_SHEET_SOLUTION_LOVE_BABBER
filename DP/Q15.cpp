#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define r 1000
#define c 1000

int lcs(int a,int b,string s1, string s2,int arr[r][c]){
    if(a == -1 || b == -1)
    {
        return 0;
    }
    if(arr[a][b] != -1){
        return arr[a][b];
    }
    if(s1[a] == s2[b] && a!=b){
        arr[a][b] = 1+lcs(a-1,b-1,s1,s2,arr);
        return arr[a][b];
    }
    else{
        arr[a][b] = max(lcs(a,b-1,s1,s2,arr),lcs(a-1,b,s1,s2,arr));
        return arr[a][b];
        
    }
}

void solution()
{
 int n;
 cin>>n;
 int arr[r][c];
 memset(arr,-1,sizeof(arr));
 string str;
 cin>>str;
 
 //recursive
 //cout<<lcs(n-1,n-1,str,str,arr)<<endl;
 
 //top down

 
    // Create and initialize DP table
    int dp[n+1][n+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 0;
 
    // Fill dp table (similar to LCS loops)
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            // If characters match and indexes are 
            // not same
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];          
                      
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout<<dp[n][n]<<endl;
 
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