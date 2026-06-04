class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total=0;
        for(int i=num1;i<=num2;i++){
            if(i<100) continue;
            string s=to_string(i);
            int curWave=0;
            int l=s.length();
            for(int j=1;j<l-1;j++){
                int prev=s[j-1]-'0';
                int cur=s[j]-'0';
                int next=s[j+1]-'0';
                if(cur>prev && cur>next) curWave++;
                else if(cur<prev && cur<next) curWave++;
            }
            total+=curWave;
        }
        return total;
    }
};