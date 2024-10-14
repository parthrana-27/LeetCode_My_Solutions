typedef struct {
    int index;
    char character;
}queue;
int firstUniqChar(char* s) {
    int count[26] = {0};
    queue q[100000];
    int front = 0;
    int rear = 0;

    for (int i = 0; s[i]!='\0';i++) {
        char ch=s[i];
        count[ch-'a']++;

        if (count[ch-'a']==1) {
            q[rear].index=i;
            q[rear].character=ch;
            rear++;
        }
        while (front < rear && count[q[front].character - 'a'] > 1) {
            front++;
        }
    }
    if (front<rear) {
        return q[front].index;
    }
    return -1;
}