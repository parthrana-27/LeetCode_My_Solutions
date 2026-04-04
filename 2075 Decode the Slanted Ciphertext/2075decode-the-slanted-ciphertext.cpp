class Solution {
public:
    string decodeCiphertext(string encode, int rows) {
        if(rows==1) return encode;
        int cols=encode.size()/rows;
        string decode="";
        for(int j=0;j<cols;j++){
            int r=0,c=j;
            while(r<rows && c<cols){
                decode+=encode[r*cols+c];
                r++;
                c++;
            }
        }
        while(!decode.empty() && decode.back()== ' ') decode.pop_back();
        return decode;
    }
};