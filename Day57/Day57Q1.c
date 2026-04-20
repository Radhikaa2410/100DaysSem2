//Problem Statement: Convert a binary tree into its mirror image by swapping left and right children at every node.

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
struct Node* queue[1000];
int front = 0, rear = 0;
void enqueue(struct Node* node) {
    queue[rear++] = node;
}
struct Node* dequeue() {
    return queue[front++];
}
struct Node* buildTree(int n) {
    if (n == 0) return NULL;
    int val;
    scanf("%d", &val);
    if (val == -1) return NULL;
    struct Node* root = newNode(val);
    enqueue(root);
    int count = 1;
    while (count < n) {
        struct Node* current = dequeue();
        scanf("%d", &val);
        count++;
        if (val != -1) {
            current->left = newNode(val);
            enqueue(current->left);
        }
        if (count >= n) break;
        scanf("%d", &val);
        count++;
        if (val != -1) {
            current->right = newNode(val);
            enqueue(current->right);
        }
    }
    return root;
}
void mirror(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter level order traversal:\n");
    struct Node* root = buildTree(n);
    mirror(root);
    printf("Inorder of mirrored tree:\n");
    inorder(root);
    return 0;
}

/*Output
Enter number of nodes: 7
Enter level order traversal:
1 2 3 4 5 6 7
Inorder of mirrored tree:
7 3 6 1 5 2 4
*/