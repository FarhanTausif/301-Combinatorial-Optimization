#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_NODES 256

// Structure to represent a tree node
struct node {
    unsigned char data;         // Character data in the node
    unsigned freq;              // Frequency of the character
    struct node* left;     // Pointer to the left child node
    struct node* right;    // Pointer to the right child node
};

// Function to create a new tree node
struct node* create_node(unsigned char data, unsigned freq) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to swap two tree nodes
void swap_nodes(struct node** a, struct node** b) {
    struct node* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort tree nodes based on their frequencies using Bubble Sort
void sort_nodes(struct node* nodes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nodes[j]->freq > nodes[j + 1]->freq) {
                swap_nodes(&nodes[j], &nodes[j + 1]);
            }
        }
    }
}

// Function to build the Huffman tree
struct node* build_huffman_tree(unsigned char data[], unsigned freq[], int n) {
    struct node* nodes[MAX_TREE_NODES];
    
    // Create individual tree nodes for each character with its frequency
    for (int i = 0; i < n; i++) {
        nodes[i] = create_node(data[i], freq[i]);
    }

    int remaining_nodes = n;
    
    while (remaining_nodes > 1) {
        // Sort the nodes based on their frequencies
        sort_nodes(nodes, remaining_nodes);

        // Take the two nodes with the lowest frequencies as left and right child
        struct node* left = nodes[0];
        struct node* right = nodes[1];

        // Create a parent node with the sum of frequencies of left and right child
        struct node* parent = create_node(0, left->freq + right->freq);

        // Assign the left and right child to the parent node
        parent->left = left;
        parent->right = right;

        // Replace the first node with the parent node in the array
        nodes[0] = parent;

        // Move the last node in the array to the second position
        nodes[1] = nodes[remaining_nodes - 1];

        // Decrement the remaining nodes count
        remaining_nodes--;
    }

    // Return the root of the Huffman tree
    return nodes[0];
}

// Function to recursively print the Huffman codes for each character
void print_codes(struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    // If it's a leaf node (character node), print the code
    if (!root->left && !root->right) {
        printf("'%c': ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Function to perform Huffman encoding
void huffman_encode(unsigned char data[], unsigned freq[], int n) {
    // Build the Huffman tree
    struct node* root = build_huffman_tree(data, freq, n);

    int arr[MAX_TREE_NODES]; // Array to store the binary codes
    int top = 0;             // Top index for the array

    printf("Huffman Codes:\n");
    // Print the Huffman codes for each character
    print_codes(root, arr, top);
}

int main() {
    unsigned char data[] = {'a', 'b', 'c', 'd', 'e'};
    unsigned freq[] = {5, 9, 12, 13, 16};
    int n = sizeof(data) / sizeof(data[0]);

    huffman_encode(data, freq, n);

    return 0;
}
