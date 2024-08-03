class Solution {
public:
    int countSeniors(vector<string>& details) {
     int count=0;
     for(int i=0;i<details.size();i++)
     {
     if(details[i][10]=='M' || details[i][10]=='F'|| details[i][10]=='O')
     {
     if(size(details)<=100 && size(details[i])==15) 
     {
     int age = (details[i][11] - '0') * 10 + (details[i][12] - '0');
        if(age>60)
        {
            count++;
        }
     }  
     }
     }
     return count;
    }
};