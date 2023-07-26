#include<stdio.h>
#include<malloc.h>
struct node{
	char ch;
	int freq;
	struct node* left;
	struct node* right;
}a[4], temp;

char c[4] = {'a','b','c','d'};
int f[4] = {20,16,6,3};

void allocateMem();
void init();
void printNode();
void swap(struct node a, struct node b);

int main(){
	
    //allocateMem();
    init();
    printNode();

    for(int i = 0; i< 4-1; ++i){
        for(int j = 0; j<4-i-1; j++){
            if( a[j].freq > a[j+1].freq ) swap(a[j], a[j+1]);
        }
    }

    printNode();

	return 0;
}

// void allocateMem(){
//     for(int i =0; i<4;++i) a[i] = malloc(sizeof(struct node));
// }

void init(){
    for(int i =0; i<4;++i){
        a[i]. ch = c[i];
        a[i]. freq = f[i];
        a[i]. left = NULL;
        a[i].right = NULL; 
    }
}

void printNode(){
    for(int i =0; i<4;++i){
        printf("char: %c - freq: %d\n", a[i].ch, a[i].freq);
    }
}

void swap(struct node a, struct node b){
    temp = a;
    a = b;
    b = temp;
}