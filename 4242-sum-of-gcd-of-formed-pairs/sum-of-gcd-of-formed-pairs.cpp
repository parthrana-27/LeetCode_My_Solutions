class Solution {
private:
    long long gcd(long long a,long long b){
        while(b){
            a%=b;
            swap(a,b);
        }
        return a;
    }
public:
    long long gcdSum(vector<int>& arr) {
        int ma=arr[0];
        int n=arr.size();
        vector<int>ans(n);
        ans[0]=arr[0];
        for(int i=1;i<n;i++){
            ma=max(ma,arr[i]);
            ans[i]=gcd(ma,arr[i]);
        }
        sort(ans.begin(),ans.end());
        long long sum=0;
        int l=0,r=ans.size()-1;
        while(l<r){
            sum+=gcd(ans[l],ans[r]);
            l++;
            r--;
        }
        return sum;
    }
};