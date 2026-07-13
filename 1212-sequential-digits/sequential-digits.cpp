class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string seq="123456789";
        vector<int>ans;
        for(int len=2;len<=9;len++){
            for(int i=0;i<=9-len;i++){
                string sub=seq.substr(i,len);
                int num=stoi(sub);
                cout << num << " "; 
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
                if(num>high) return ans;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};