#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    char ch;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node* createNode(char ch, int freq) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Find index of minimum frequency node
int findMin(Node *nodes[], int size) {
    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (nodes[i]->freq < nodes[minIndex]->freq) {
            minIndex = i;
        }
    }

    return minIndex;
}

// Build Huffman Tree
Node* buildHuffmanTree(Node *nodes[], int n) {
    int size = n;

    while (size > 1) {

        // Find first minimum
        int min1 = findMin(nodes, size);
        Node *left = nodes[min1];

        nodes[min1] = nodes[size - 1];
        size--;

        // Find second minimum
        int min2 = findMin(nodes, size);
        Node *right = nodes[min2];

        nodes[min2] = nodes[size - 1];
        size--;

        // Combine both nodes
        Node *parent = createNode(
            '\0',
            left->freq + right->freq
        );

        parent->left = left;
        parent->right = right;

        // Add parent back
        nodes[size] = parent;
        size++;
    }

    return nodes[0];
}

// Print Huffman codes
void printCodes(Node *root, int code[], int depth) {

    if (root == NULL)
        return;

    // Go left -> 0
    if (root->left != NULL) {
        code[depth] = 0;
        printCodes(root->left, code, depth + 1);
    }

    // Go right -> 1
    if (root->right != NULL) {
        code[depth] = 1;
        printCodes(root->right, code, depth + 1);
    }

    // Leaf node
    if (root->left == NULL && root->right == NULL) {

        printf("%c: ", root->ch);

        // Special case: only one character
        if (depth == 0) {
            printf("0");
        } else {
            for (int i = 0; i < depth; i++) {
                printf("%d", code[i]);
            }
        }

        printf("\n");
    }
}

int main() {
    int n;

    scanf("%d", &n);

    Node *nodes[n];

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;

        scanf(" %c %d", &ch, &freq);

        nodes[i] = createNode(ch, freq);
    }

    Node *root = buildHuffmanTree(nodes, n);

    int code[n];

    printCodes(root, code, 0);

    return 0;
}