//Problem Statement:Check whether a given binary tree satisfies the Min-Heap property.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int isComplete(struct Node* root, int index, int total) {
    if (root == NULL)
        return 1;
    if (index >= total)
        return 0;
    return isComplete(root->left, 2 * index + 1, total) &&
           isComplete(root->right, 2 * index + 2, total);
}
int isMinHeap(struct Node* root) {
    if (root->left == NULL && root->right == NULL)
        return 1;
    if (root->right == NULL)
        return (root->data <= root->left->data) &&
               isMinHeap(root->left);
    else {
        if (root->data <= root->left->data &&
            root->data <= root->right->data)
            return isMinHeap(root->left) &&
                   isMinHeap(root->right);
        else
            return 0;
    }
}
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;
    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);
    return root;
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter level order traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n, 0);
    int total = countNodes(root);
    if (isComplete(root, 0, total) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");
    return 0;
}

/*Output
Enter number of nodes: 6
Enter level order traversal: 10 15 20 30 40 50
YES
*/