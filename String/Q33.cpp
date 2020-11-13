#include<iostream>
#define MAX_CHAR 256

using namespace std;

void solution()
{
    string str;
    cin>>str;
    int map[MAX_CHAR]= {0};
    int n=str.size(),dis_count=0;
    //finding no of distinct element
    for(int i=0;i<n;i++){
        if(map[str[i]]==0){
          dis_count++;
        }
        map[str[i]]++;
    }
    

    int start=0,min_diff=10000000;
    int map1[MAX_CHAR]= {0};
    int count=0;
    for(int j=0; j<n;j++){
        if(map1[str[j]]==0)
        {
            //cout<<j<<":"<<count<<endl;
            count++;
        }
        map1[str[j]]++;
          
         
         if(count>=dis_count){
             while(map1[str[start]]>1){
                 //cout<<"hello"<<j<<":"<<str[start]<<":"<<map1[str[start]]<<endl;
                 map1[str[start]]--;
                 start++;
             }
             int diff=(j-start)+1;
             if(diff<min_diff)
               min_diff=diff;
         }
    }
    
    cout<<min_diff<<endl;
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