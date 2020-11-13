class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.size()==0)
         return "";
        int length=strs[0].size();
        string out="",tmp;
        for(int i=0;i<length;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]==strs[0][i]){
                    continue;
                }
                else{
                    return out;
                }
            }
            out=out+strs[0][i];       
        }
       return out;            
    }
    
};