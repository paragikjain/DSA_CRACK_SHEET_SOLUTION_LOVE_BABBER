#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void permutation(string input,int low, int high, vector<string> &vect){
    if(low==high)
    {
      vect.push_back(input);
      return;
    }
    
    for(int i=low;i<=high;i++){
        //swapping first elements with all other element.
        swap(input[low],input[i]);
        //doing same process
        permutation(input,low+1,high,vect);
        //reaggring sring back (backtracking)
        swap(input[low],input[i]);
        
    }
    
    
}
void solution()
{
  string input;
  cin>>input;
  vector<string> vect;
  permutation(input,0,input.length()-1,vect);
  sort(vect.begin(),vect.end());
  
  for(auto i:vect)
    cout<<i<<" ";
  cout<<endl;
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