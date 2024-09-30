bool isValid(char* s) {
    int len=strlen(s);
    char *stack=(char*)malloc((len+1)*sizeof(char));
    int top=-1;
    for(int i=0;i<len;i++)
    {
        char ch=s[i];
        if(ch=='('||ch=='{'||ch=='[')
        {
            stack[++top]=ch;
        }
        else{
            if(top==-1)
            {
                free(stack);
                return 0;
            }
            else{
            char topch=stack[top];
            if((ch==')'&&topch=='(')||
            (ch=='}'&&topch=='{')||
            (ch==']'&&topch=='[')){
                top--;
            }
            else{
                free(stack);
                return false;
            }
            }
        }
    }
            int result=(top==-1)?1:0;
            free(stack);
            return result;
}
