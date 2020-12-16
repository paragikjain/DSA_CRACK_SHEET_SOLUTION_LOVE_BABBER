class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n=nums.size();
      int start = 0;
      int end = n-1;
      
      int first = nums[0];
      while(start<=end){
        int mid =  (start+end)/2;
        if(nums[mid]==target){
          return mid;
        }
        bool mid_is_big = (nums[mid]>=first);
        bool target_is_big = (target>=first);
        if(mid_is_big == target_is_big){
          if(nums[mid]<target)
            start=mid+1;
          else
            end=mid-1;
        }
        else{
          if(mid_is_big){
            start = mid +1;
          }else{
            end = mid-1;
          }
        }
      }
      return -1;
    }
};