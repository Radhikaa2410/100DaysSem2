#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find minimum meeting rooms
int minMeetingRooms(int intervals[][2], int intervalsSize) {

    if (intervalsSize == 0)
        return 0;

    int *start = (int *)malloc(intervalsSize * sizeof(int));
    int *end = (int *)malloc(intervalsSize * sizeof(int));

    // Separate start and end times
    for (int i = 0; i < intervalsSize; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    // Sort both arrays
    qsort(start, intervalsSize, sizeof(int), compare);
    qsort(end, intervalsSize, sizeof(int), compare);

    int rooms = 0;
    int maxRooms = 0;
    int endPtr = 0;

    // Two pointer technique
    for (int i = 0; i < intervalsSize; i++) {

        // Need new room
        if (start[i] < end[endPtr]) {
            rooms++;
        }
        // Meeting ended, reuse room
        else {
            endPtr++;
        }

        // Track maximum rooms needed
        if (rooms > maxRooms) {
            maxRooms = rooms;
        }
    }

    free(start);
    free(end);

    return maxRooms;
}

// Main function
int main() {

    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int intervals[n][2];

    printf("Enter start and end times:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    int result = minMeetingRooms(intervals, n);

    printf("Minimum meeting rooms required = %d\n", result);

    return 0;
}