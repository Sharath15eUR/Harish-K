#include <stdio.h>

int main(){
    int r, c, i, j;
    printf("Size of Row: ", &r);
    scanf("%d", &r);
    printf("Size of Column: ", &c);
    scanf("%d", &c);
    int a[r][c], b[r][c], pro[r][c], k;
    printf("Matrix 1:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d", *(a+i)+j);
        }
    }
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d", *(b+i)+j);
        }
    }
    printf("%d\n", *(*(a+0)+0));
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            *(*(pro+i)+j)=0;
            for(k=0; k<c; k++){
                *(*(pro+i)+j) += *(*(a+i)+k)**(*(b+k)+j);
            }
            printf("%d ", *(*(pro+i)+j));
        }
        printf("\n");
    }
    
}