#include<iostream>

using namespace std;

void solution(string str)
{
    if(str.size()<=1)
    {  
        cout<<str;
        return ;
    }
    if(str[0]==str[1])
      solution(str.substr(1));
    else
    {
      cout<<str[0];
      solution(str.substr(1));
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string input;
        cin>>input;
        solution(input);
        cout<<endl;
    }
  
}