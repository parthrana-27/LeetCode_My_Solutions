class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(char ch:letters) freq[ch-'a']++;
        return backtrack(0,words,freq,score);
    }
    int backtrack(int idx,vector<string>& words,vector<int>& freq,vector<int>& score){
        if(idx==words.size()) return 0;
        int skip=backtrack(idx+1,words,freq,score);
        string& word = words[idx];
        bool canTake = true;
        int wordScore = 0;
        vector<int> used(26, 0);
        for (char ch : word) {
            int i = ch-'a';
            used[i]++;
            if (used[i] >freq[i]) {
                canTake = false;
                break;
            }
            wordScore += score[i];
        }
        int take = 0;
        if (canTake) {
            for (int i = 0;i<26;++i) freq[i] -=used[i];
            take = wordScore + backtrack(idx + 1, words, freq, score);
            for (int i = 0;i< 26;++i) freq[i] += used[i];
        }
        return max(skip,take);
    }
};