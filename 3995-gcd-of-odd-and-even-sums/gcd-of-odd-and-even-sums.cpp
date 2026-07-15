class Solution {
private:
    int gcd(int a,int b){
        while(b){
            a%=b;
            swap(a,b);
        }
        return a;
    }
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1));
    }
};