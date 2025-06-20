class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        priority_queue<pair<int,char>>pq;
        for(char ch:s)
        {
            freq[ch]++;
        }
        for(auto i:freq)
        {
            char ch=i.first;
            int f=i.second;
            pq.push({f,ch});
        }
        string res="";
        while(!pq.empty())
        {
            auto i=pq.top();
            pq.pop();
            
            while(i.first!=0)
            {
                res+=i.second;
                i.first--;
            }
        }
        return res;
        
    }
};