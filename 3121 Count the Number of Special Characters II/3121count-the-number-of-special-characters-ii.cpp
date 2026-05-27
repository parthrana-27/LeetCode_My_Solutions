class Solution {
public:
    int numberOfSpecialChars(string word) {
       vector<int>up(26,-1);
       vector<int>lower(26,-1);
       for(int i=0;i<word.length();i++){
        int c=word[i];
        if(c>='a' && c<='z'){
            lower[c-'a']=i;
        }else{
           int idx=c-'A';
           if(up[idx]==-1){
            up[idx]=i;
           }
        }
       }
       int c=0;
       for(int i=0;i<26;i++){
        if(lower[i]!=-1 && up[i] != -1 && lower[i]<up[i]) c++;
       }
       return c;
   }
};