#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
void dfs(int** rooms, int roomsSize, int* roomsColSize, int room, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(rooms, roomsSize, roomsColSize, key, visited);
        }
    }
}

// Function to check if all rooms can be visited
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];

    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    dfs(rooms, roomsSize, roomsColSize, 0, visited);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

// Main function
int main() {
    int n;

    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int** rooms = (int**)malloc(n * sizeof(int*));
    int* roomsColSize = (int*)malloc(n * sizeof(int));

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter number of keys in room %d: ", i);
        scanf("%d", &roomsColSize[i]);

        rooms[i] = (int*)malloc(roomsColSize[i] * sizeof(int));

        printf("Enter keys for room %d: ", i);
        for (int j = 0; j < roomsColSize[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    // Function call
    bool result = canVisitAllRooms(rooms, n, roomsColSize);

    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(rooms[i]);
    }
    free(rooms);
    free(roomsColSize);

    return 0;
}