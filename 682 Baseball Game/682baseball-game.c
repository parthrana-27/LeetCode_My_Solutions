int calPoints(char** operations, int operationsSize) {
    int n=operationsSize;
    int stack[1000];
    int top=-1;
    int cur=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
            if(operations[i][0]=='C'){
                stack[top--]=0;
            }
            else if(operations[i][0]=='D')
            {
                cur = stack[top]*2;
                stack[++top]=cur;
            }
            else if(operations[i][0]=='+')
            {
                cur=stack[top-1]+stack[top];
                stack[++top] = cur;
            }
            else{
                cur=atoi(operations[i]);
                stack[++top]=cur;
            }
    }
    for(int i=0;i<=top;i++)
    {
        sum+=stack[i];
    }
    return sum;
}