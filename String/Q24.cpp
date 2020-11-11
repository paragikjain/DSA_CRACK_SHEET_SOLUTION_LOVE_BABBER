#include<iostream>
#define ROW_MAX 100
#define COL_MAX 100
using namespace std;

int lookin8direction(char input[ROW_MAX][COL_MAX],int row, int col, int row_max, int col_max,string key){
  int count =0;
  int key_size=key.size()-1;
  //looking right
  if(col+key_size<=col_max){
      int tmp =col;
      int signal=0;
      for(int i=0;i<=key_size;i++){
          //cout<<input[tmp][y]<<endl;
          if(input[row][tmp]!=key[i]){
              signal =1;
              break;
          }
          tmp++;
      }
      if(signal == 0){
          cout<<row<<" "<<col<<", ";
          return 1;
      }
  }
  
  //looking left
  if(col-key_size>=0){
      int tmp =col;
      int signal=0;
      for(int i=0;i<=key_size;i++){
          if(input[row][tmp]!=key[i]){
              signal =1;
              break;
          }
          tmp--;
      }
      if(signal == 0){
          cout<<row<<" "<<col<<", ";
          return 1;
      }    
  }

  //looking up
  if(row-key_size>=0){
      int tmp =row;
      int signal=0;
      for(int i=0;i<=key_size;i++){
          if(input[tmp][col]!=key[i]){
              signal =1;
              break;
          }
          tmp--;
      }
      if(signal == 0){
          cout<<row<<" "<<col<<", ";
          return 1;
      }    
  }

  //looking down
  if(row+key_size<=row_max){
      int tmp =row;
      int signal=0;
      for(int i=0;i<=key_size;i++){
          if(input[tmp][col]!=key[i]){
              signal =1;
              break;
          }
          tmp++;
      }
      if(signal == 0){
          cout<<row<<" "<<col<<", ";
          return 1;
      }    
  }
  
  //looking upright
  if(col+key_size<=col_max && row-key_size>=0 ){
      int tmp_x =row;
      int tmp_y =col;
      int signal=0;
      for(int i=0;i<=key_size;i++){
          if(input[tmp_x][tmp_y]!=key[i]){
              signal =1;
              break;
          }
          tmp_x--;
          tmp_y++;
      }
      if(signal == 0){
          cout<<row<<" "<<col<<", ";
          return 1;
      } 
      
  }
  
  //down right
  if(col+key_size<=col_max && row+key_size<=row_max){
      int tmp_x =row;
      int tmp_y =col;
      int signal=0;
      for(int i=0;i<=key_size;i++){
          if(input[tmp_x][tmp_y]!=key[i]){
              signal =1;
              break;
          }
          tmp_x++;
          tmp_y++;
      }
      if(signal == 0){
          cout<<row<<" "<<col<<", ";
          return 1;
      }       
  }

//   //looking up left
  if(row-key_size>=0 && col-key_size>=0){
      int tmp_x =row;
      int tmp_y =col;
      int signal=0;
      for(int i=0;i<=key_size;i++){
          if(input[tmp_x][tmp_y]!=key[i]){
              signal =1;
              break;
          }
          tmp_x--;
          tmp_y--;
      }
      if(signal == 0){
          cout<<row<<" "<<col<<", ";
          return 1;
      }     
  }

  //looking  down left
  if(row+key_size<=row_max && col-key_size>=0){
      int tmp_x =row;
      int tmp_y =col;
      int signal=0;
      for(int i=0;i<=key_size;i++){
          if(input[tmp_x][tmp_y]!=key[i]){
              signal =1;
              break;
          }
          tmp_x++;
          tmp_y--;
      }
      if(signal == 0){
          cout<<row<<" "<<col<<", ";
          return 1;
      }     
  }
  
   return count;
}

void solution()
{
  int n,m,count=0;
  cin>>n>>m;
  char input[ROW_MAX][COL_MAX];
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>input[i][j];
      }
  }
  string key;
  cin>>key;
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(input[i][j]==key[0])
          { 
              count+=lookin8direction(input,i,j,n-1,m-1,key);
          }
      }
  }
  if(count==0){
      cout<<-1<<endl;
  }
  else{
      cout<<endl;
  }
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