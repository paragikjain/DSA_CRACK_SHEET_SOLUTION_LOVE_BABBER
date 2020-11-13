// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// return the smallest window in S with all the characters of P
// if no such window exists, return "-1" 
string smallestWindow (string s1, string s2){
  int l1=s1.length();
    int l2=s2.length();
    
    if(l1<l2)
        return "";
        
    int hash_p[256]={0};
    int hash_h[256]={0};
    
    for(int i=0;i<l2;i++)
        hash_p[s2[i]]++;
    
    int count=0,start=0,start_index=-1, min_length=INT_MAX;
    for(int i = 0;i<l1;i++)
    {
        hash_h[s1[i]]++;
        
        if(hash_p[s1[i]]!=0 && hash_p[s1[i]]>=hash_h[s1[i]])
            count++;
        
        if(count==l2)
        {
            while(hash_h[s1[start]]>hash_p[s1[start]] || hash_p[s1[start]]==0)
            {
                if(hash_h[s1[start]]>hash_p[s1[start]])
                    hash_h[s1[start]]--;
                start++;    
            }

        
        int min_window=i-start+1;
        if(min_length>min_window)
        {
            start_index = start;
            min_length=min_window;
        }   
        }
        
    }
    if (start_index == -1)
    {
        return "";
    }
    return s1.substr(start_index,min_length);

}

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        
        cout<<smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends