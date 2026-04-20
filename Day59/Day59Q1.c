//Problem Statement:Construct a binary tree from given inorder and postorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;
    int curr = postorder[*postIndex];
    (*postIndex)--;
    struct Node* node = newNode(curr);
    if (start == end)
        return node;
    int pos = search(inorder, start, end, curr);
    node->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, pos - 1, postIndex);
    return node;
}
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int inorder[n], postorder[n];
    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    printf("Enter postorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }
    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);
    printf("Preorder traversal:\n");
    preorder(root);
    return 0;
}

/*Output
Enter inorder traversal:
1 2 3 4 5 6 7
Enter postorder traversal:
4 5 3 6 2 7 1
Preorder traversal:
1 7 2 6 3 5 4 
*/