//slower solution (we will check each time one by one merge two and earse one)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.size()<2){
         return intervals;
      }
      sort(intervals.begin(),intervals.end());
      for(int i=0;i<intervals.size()-1;i++)
      {
        if(intervals[i][1]>=intervals[i+1][0])
        {
          intervals[i][1]=intervals[i][1]>=intervals[i+1][1]?intervals[i][1]:intervals[i+1][1];
          intervals.erase(intervals.begin()+i+1);
          i=i-1;
        }
      }
      return intervals;
    }
};

//faster solution (we will contiounsly check until merge can not possible then we push to temp array)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.size()<2){
         return intervals;
      }
        auto sortLambda = [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; };
        std::sort(intervals.begin(), intervals.end(), sortLambda);
      vector<vector<int>> result;
      for(int i=0;i<intervals.size();i++)
      {  int from=intervals[i][0];
         int to = intervals[i][1];
       
         for(int j=i+1;j<intervals.size() && to>=intervals[j][0] ;j++,i++)
         {
            
              to=std::max(to, intervals[j][1]);
            
         }
          result.push_back({from,to});
       }
          return result;
    }
};