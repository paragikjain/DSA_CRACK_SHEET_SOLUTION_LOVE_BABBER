//100% fastest solution in leet code
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int i;
      //finding the first decrement element from backside  
      for( i=nums.size()-1 ;i>0;i--)
      {
        if(nums[i]>nums[i-1]){
          break;
        }
      }
      //if decrement element is present then we will find nearest greater element from decresing element
      if(i>0)
      {
        int target=nums[i-1],near=1000,index,j;
        for( j=i;j<nums.size();j++)
        { if(nums[j]-target>0 && nums[j]-target<=near)
          {
            near=nums[j]-target;
            index=j;
          }
        }
        //once we get neareset greater from decresing element we will swap both
        swap(nums[i-1],nums[index]);
        //rest of array we can sort but as we know after target element all numbers are in decresing order we can reverse it and find the sorted array
        reverse(nums.begin()+i,nums.end());
      }
      else// if no deresed element found then we reerse whole array to find smallest permutataion
      {
        reverse(nums.begin(),nums.end());
      }
      
    }
};