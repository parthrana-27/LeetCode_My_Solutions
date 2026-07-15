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
        int OddSum=n*n;
        int EvenSum=n*(n+1);
        return gcd(OddSum,EvenSum);
    }
};