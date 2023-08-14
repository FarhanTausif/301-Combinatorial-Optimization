#include<stdio.h>
#include<string.h>

#define LEFTARROW 1
#define UPARROW 2
#define DIAGONALARROW 3
#define DIAGONALNILARROW 4

int c[100][100];
int sign[100][100];
// int _min(int a, int b){
//     if(a < b) return a;
//     else return b;
// }

// int __min(int a, int b, int c){
//     return(_min(_min(a,b),c));
// }

int __min(int a, int b, int c){
    if((a <= b) && (a <= c)) return a;
    else if((b <= a) && (b <= c)) return b;
    else return c;    
}

int main(){
    char s1[25], s2[25];
    printf("Enter two strings:\n");
    scanf("%s %s", s1, s2);

    int i = strlen(s1) + 1;
    int j = strlen(s2) + 1;

    printf("%d %d\n", i, j);

    for(int p = 0; p < i; ++p){
        for(int q = 0; q < j; ++q){
            if(q == 0){ 
                c[p][q] = p;
                sign[p][q] = UPARROW;
            }
            else if(p == 0){ 
                c[p][q] = q;
                sign[p][q] = LEFTARROW;
            }
            else if(s1[p] == s2[q]){ 
                c[p][q] = c[p-1][q-1];
                sign[p][q] = DIAGONALNILARROW;
            }
            else{
                c[p][q] = __min(c[i-1][j-1], c[i-1][j], c[i][j-1]) + 1;
                sign[p][q] = DIAGONALARROW;
            }
        }
    }

    printf("C Array:\n");

    for(int p = 0; p < i; ++p){
        for(int q = 0; q < j; ++q){
            printf("%d ", c[p][q]);
        }
        printf("\n");        
    }

    printf("Sign Array:\n");

    for(int p = 0; p < i; ++p){
        for(int q = 0; q < j; ++q){
            if(sign[p][q] == UPARROW) printf("| ");
            else if(sign[p][q] == LEFTARROW) printf("<- ");
            else if(sign[p][q] == DIAGONALARROW) printf("\\ ");
            else if(sign[p][q] == DIAGONALNILARROW) printf("\\\\ ");
        }
        printf("\n");        
    }

    return 0;
}