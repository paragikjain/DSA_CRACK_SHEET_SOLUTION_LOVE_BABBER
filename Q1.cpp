#include<iostream>
#include<string.h>
using namespace std;
void solution()
{
  int i;
  char s[1000];
  scanf("%s",s);
  int n=strlen(s);
   for(i=n-1;i>=0;i--)
   {
      printf("%c",s[i]);
   }
	   printf("\n");
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
