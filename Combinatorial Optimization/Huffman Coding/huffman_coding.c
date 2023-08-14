#include<stdio.h>
#include<malloc.h>

#define n 4

struct node{
	char ch;
	int freq;
	struct node* left;
	struct node* right;
}*a[n];

int arr[n];

char c[n] = {'a','b','c','d'};
int f[n] = {5,8,15,20};

void allocateMem();
void init();
void printNode();
void swap(struct node **a, struct node **b);
void sortNode();
struct node* buildHuffmanTree();
void print_codes(struct node* root, int arr[], int top);

int main(){
	
    allocateMem();
    init();
    printNode();
    // printf("\n--------------------------------------\n\n");
    // printNode();
    buildHuffmanTree();
    // print_codes();
    	
    return 0;
}

void allocateMem(){
    for(int i =0; i<n;++i) a[i] = malloc(sizeof(struct node));
}

void init(){
    for(int i =0; i<n;++i){
        a[i]-> ch = c[i];
        a[i]-> freq = f[i];
        a[i]-> left = NULL;
        a[i]->right = NULL; 
    }
}

void printNode(){
    for(int i =0; i<n;++i){
        printf("char: %c - freq: %d\n", a[i]->ch, a[i]->freq);
    }
}

void swap(struct node **a, struct node **b){
    struct node *temp = malloc(sizeof(struct node));
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortNode(){
    for(int i = 0; i< n-1; ++i){
        for(int j = 0; j<n-i-1; j++){
            if( a[j]->freq > a[j+1]->freq ) swap(&a[j], &a[j+1]);
        }
    }
}

struct node* buildHuffmanTree(){

    int remainingNodes = n; 
    
    while(remainingNodes>1){
        
        sortNode();
        struct node* left = a[0];
        struct node* right = a[1];
        struct node* parent = malloc(sizeof(struct node));
        
        parent->ch = 'x';
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;
        
        a[0] = parent;        
        a[1] = a[remainingNodes-1];
        
        remainingNodes--;
        
        printf("%d Lf:%d Rf:%d Lc:%c Rc:%c\n", parent->freq, parent->left->freq,parent->right->freq, parent->left->ch, parent->right->ch);
        printf("\n-------------------------------------\n\n");
        printNode();

    }
    return a[0];   
}

void huffman_encode() {
    // Build the Huffman tree
    struct node* root = buildHuffmanTree();

    //int arr[MAX_TREE_NODES]; // Array to store the binary codes
    int top = 0;             // Top index for the array

    printf("Huffman Codes:\n");
    // Print the Huffman codes for each character
    print_codes(root, arr, top);
}

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
        printf("'%c': ", root->ch);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

