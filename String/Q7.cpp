class Solution {
public:
    string countAndSay(int x) {
       if(x==1){
         return "1";
       }
       
      string a= countAndSay(x-1);
      
      string outstr="";
       int n=a.size();
       char prev=a[0];
       int count=1;
      for(int i=1;i<n;i++){
        if(prev==a[i]){
          count++;
          continue;
        }
        else
          outstr=outstr+to_string(count)+prev;
        prev=a[i];
        count=1;
      }
      outstr=outstr+to_string(count)+prev;
      return outstr;
    }
};