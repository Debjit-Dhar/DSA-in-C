#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b) {
    return a < b ? a : b;
}

int isMAnagram(char s[], char t[], int M) {
    int freqS[26] = {0};
    int freqT[26] = {0};
    int lenS = strlen(s);
    int lenT = strlen(t);
    
    if (lenS != lenT) {
        return 0; // Strings don't have the same number of characters
    }
    
    for (int i = 0; i < lenS; i++) {
        freqS[s[i] - 'a']++;
        freqT[t[i] - 'a']++;
    }
    
    int diffCount = 0; // Count of characters that need to be changed
    
    for (int i = 0; i < 26; i++) {
        if (freqS[i] > freqT[i]) {
            diffCount += freqS[i] - freqT[i];
        }
    }
    
    return diffCount <= M;
}

int minOperations(char s[], char t[]) {
    int lenS = strlen(s);
    int lenT = strlen(t);
    
    int dp[lenS + 1][lenT + 1];
    
    for (int i = 0; i <= lenS; i++) {
        for (int j = 0; j <= lenT; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
    }
    
    return dp[lenS][lenT];
}

int main() {
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];
    int M;
    
    printf("Enter the first string: ");
    scanf("%s", s);
    
    printf("Enter the second string: ");
    scanf("%s", t);
    
    printf("Enter the value of M: ");
    scanf("%d", &M);
    
    if (isMAnagram(s, t, M)) {
        int operations = minOperations(s, t);
        printf("The strings are %d-anagrams.\n",M);
        printf("Minimum operations required: %d\n", operations);
    } else {
        printf("The strings are not M-anagrams.\n");
    }
    
    return 0;
}
