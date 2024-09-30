char* removeDuplicates(char* s) {
    int n = strlen(s);
    int j=0;
    for (int i = 0; i < n; i++) {
        if ( j > 0 && s[j - 1] == s[i]) {
            j--;
        } else {
            s[j++] = s[i];
        }
    }    
    s[j] = '\0';
    return s;
}