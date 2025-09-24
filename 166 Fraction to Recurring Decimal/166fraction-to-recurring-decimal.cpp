class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num==0) return "0"; 
        string res="";
        if(num<0 ^ den<0) res+="-";
        long n=labs(num);
        long d=labs(den);
        res+=to_string(n/d);
        long rem=n%d;
        if(rem==0) return res;
        res+=".";
        unordered_map<long,int>seen;
        while(rem!=0)
        {
            if(seen.find(rem)!=seen.end()){
            res.insert(seen[rem],"(");
            res+=")";
            break;
        }
        seen[rem]=res.size();
        rem*=10;
        res+=to_string(rem/d);
        rem%=d;
    }
    return res;
    }
};