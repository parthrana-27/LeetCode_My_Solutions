class Solution {
    private:
    int f(vector<int>&arr,int pages){
        int stu=1,page_stu=0;
        for(int i=0;i<arr.size();i++){
            if(page_stu+arr[i]<=pages){
                page_stu+=arr[i];
            }
            else{
                stu++;
                page_stu=arr[i];
            }
        }
        return stu;
    }
public:
    int splitArray(vector<int>& arr, int k) {
        if(k>arr.size()) return -1;
        int ma=INT_MIN,sum=0;
        for(int i=0;i<arr.size();i++){
            ma=max(ma,arr[i]);
            sum+=arr[i];
        }
        int l=ma,r=sum;
        while(l<=r){
            int mid=(l+r)/2;
            int cnt=f(arr,mid);
            if(cnt>k) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};