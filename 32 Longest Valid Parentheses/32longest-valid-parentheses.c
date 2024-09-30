int longestValidParentheses(char* s) {
   int len = strlen(s);
    int* stack = (int*)malloc(sizeof(int) * (len + 1));
    int top = -1;
    int m = 0;
    stack[++top] = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top == -1) {
                stack[++top] = i;
            } else {
                int cur = i - stack[top];
                if (cur > m) {
                    m = cur;
                }
            }
        }
    }
    free(stack);
    return m;
}