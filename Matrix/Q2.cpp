class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int row=matrix.size();
      if(row==0)
        return false;
      int cols=matrix[0].size();
      int target_row=-1;
      if(cols==0)
        return false;
      
      //finding target row
      for(int i =0;i<row;i++){
        if(matrix[i][0]<=target && target<=matrix[i][cols-1]){
          target_row=i;
          break;
        }
      }
      
      //if target row not exist means value not exist
      if(target_row==-1){
        return false;
      }//target row exist so we can apply binary search
      else{
        int low=0;
        int high=cols-1;
        while(low<=high){
          int mid=(high+low)/2;
          //cout<<matrix[target_row][mid]<<" ";
          if(matrix[target_row][mid]==target)
            return true;
          if(matrix[target_row][mid]>target)
            high=mid-1;
          else
            low=mid+1;
        }
      }
      
      
      return false;
      
    }
};