class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int mi=INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int c=(i-startIndex+n)%n;
                int u=n-c;
                mi=min(mi,min(c,u));
            }
        }
        return mi==INT_MAX?-1:mi;
    }
};