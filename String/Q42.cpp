// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}// } Driver Code Ends


// This function returns true if str1 and str2 are ismorphic
// else returns false
//a jisse phli baar map hua h same charecter se dusri baar bhi map ho.
#include <bits/stdc++.h>
bool areIsomorphic(string str1, string str2)
{
    if(str1.size()!=str2.size()){
      return false;
        
    }
    unordered_map<char,char> umap;
    unordered_map<char,bool> existInstr2;
    
    for(int i=0;i<str1.size();i++){
        //it is not in map
        if(umap[str1[i]]==0){
            //if char 2 is already in map
            if(existInstr2[str2[i]]== true)
              return false;
            
            existInstr2[str2[i]]=true; 
            umap[str1[i]]=str2[i];
        }
        else if (umap[str1[i]] != str2[i]) 
            return false; 
        
    }
    
    return true;
}