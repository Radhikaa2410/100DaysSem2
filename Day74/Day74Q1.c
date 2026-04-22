//Problem Statement Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char votes[n][50];
    char names[n][50];
    int count[n];
    int unique = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < unique; j++) {
            if (strcmp(votes[i], names[j]) == 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            count[found]++;
        } else {
            strcpy(names[unique], votes[i]);
            count[unique] = 1;
            unique++;
        }
    }
    int maxVotes = count[0];
    char winner[50];
    strcpy(winner, names[0]);
    for (int i = 1; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }
    printf("%s %d\n", winner, maxVotes);
    return 0;
}

/*Output
10
john jack jacky john john jack jack jack jacky john          
jack 4
*/