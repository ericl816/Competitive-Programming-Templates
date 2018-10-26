#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int C, R, i, iMirror, maxLPSLength, maxLPSCenterPosition;
int L[MAXN]; // LPS Length Array
char text[MAXN];
string s, ans;

// Gets the longest palindromic string that is contained in the word
string Manachers () {
    int N = strlen(text);
    if (N == 0) return "";
    N = N << 1 | 1; // Position count
    L[0] = 0;
    L[1] = 1;
    C = 1; // centerPosition 
    R = 2; // centerRightPosition
    i = 0; // currentRightPosition
    iMirror; // currentLeftPosition
    maxLPSLength = 0;
    maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;
     
    // Uncomment it to print LPS Length array printf("%d %d ", L[0], L[1]);
    for (i=2; i<N; i++) {
        // Get currentLeftPosition iMirror for currentRightPosition i
        iMirror  = (C << 1) - i;
        L[i] = 0;
        diff = R - i;
        // If currentRightPosition i is within centerRightPosition R
        if (diff > 0) L[i] = min(L[iMirror], diff);
 
        // Attempt to expand palindrome centered at currentRightPosition i
        // Here for odd positions, we compare characters and if they match, then increment LPS Length by ONE
        // If even position, we just increment LPS by ONE without  any character comparison
        while (((i + L[i]) < N && (i - L[i]) > 0) && (!((i + L[i] + 1) & 1) || (text[(i + L[i] + 1) >> 1] == text[(i - L[i] - 1) >> 1]))) L[i]++;
 
        // Track maxLPSLength
        if (L[i] > maxLPSLength) {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
 
        // If palindrome centered at currentRightPosition i, expands beyond centerRightPosition R, simply adjust centerPosition C based on expanded palindrome.
        if (i + L[i] > R)  {
            C = i;
            R = i + L[i];
        }
        // Uncomment it to print LPS Length array
        //printf("%d ", L[i]);
    }
    //printf("\n");
    start = (maxLPSCenterPosition - maxLPSLength) >> 1;
    end = start + maxLPSLength - 1;
    //printf("LPS of string is %s : ", text);
    for (i=start; i<=end; i++) ans += text[i];
    //printf("%c", text[i]);
    // printf("\n");
    return ans;
}

int main () {
    scanf("%s", text);
    ans = Manachers();
    // Print the longest palindromic string in O(N) time using Manacher's Algorithm
    printf("%s\n", ans);
    // Get the length of the longest palindromic string in O(N) time using Manacher's Algorithm
    printf("%d\n", ans.length());
}