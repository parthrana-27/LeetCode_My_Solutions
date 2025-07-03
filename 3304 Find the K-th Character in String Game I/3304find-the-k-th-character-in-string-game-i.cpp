class Solution {
public:
    char kthCharacter(int k) {
        string res="a";
        while(res.length()<k){
            int s=res.length();
            for(int i=0;i<s;i++){
                char nextc='a'+ ((res[i]-'a'+ 1) % 26);
                res+=nextc;
            }
        }
        return res[k-1];
    }
};