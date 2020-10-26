//please creat main function and pass input

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      //find the intersection point of this cycles
        int slow,fast;
        slow=nums[0];
        fast=nums[0];
        do
        {
          slow=nums[slow];
          fast=nums[nums[fast]];
        }while(slow!=fast);
        //find the entrance of cycle
        slow=nums[0];
        while(slow!=fast)
        {
          slow=nums[slow];
          fast=nums[fast];
        }
      return slow;  
    }
};