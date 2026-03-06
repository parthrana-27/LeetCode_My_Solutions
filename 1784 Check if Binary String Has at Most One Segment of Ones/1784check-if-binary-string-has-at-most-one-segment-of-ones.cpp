class Solution {
public:
    bool checkOnesSegment(string s) {
        bool found=false;
        for(char c:s){
            if(c=='0'){
                found=true;
            }
            else{
                if(found){
                    return false;
                }
            }
        }
        return true;
    }
};