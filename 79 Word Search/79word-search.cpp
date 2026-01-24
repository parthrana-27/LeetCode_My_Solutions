class Solution {
    private:
    bool f(vector<vector<char>>& board,string &word,int i,int j,int k,int n,int m){
        if(k==word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j] != word[k]) return false;
        char temp=board[i][j];
        board[i][j]='#';
        bool found=f(board,word,i+1,j,k+1,n,m)|| f(board,word,i,j+1,k+1,n,m) || f(board,word,i-1,j,k+1,n,m) || f(board,word,i,j-1,k+1,n,m);
        board[i][j]=temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(f(board,word,i,j,0,n,m)) return true;
            }
        }
        return false;
    }
};