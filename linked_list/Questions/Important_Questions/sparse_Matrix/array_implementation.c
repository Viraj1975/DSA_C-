#include<stdio.h>

int main(){
    int row,column;
    printf("Enter the number of rows and columns respectively : ");
    scanf("%d %d",&row,&column);
    int sparseMatrix[row][column];
    printf("Enter the elements of the sparse Matrix : ");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            scanf("%d",&sparseMatrix[i][j]);
        }
    }
    int size=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(sparseMatrix[i][j]!=0){
                size++;
            }
        }
    }
    int compact_matrix[3][size];
    int q=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(sparseMatrix[i][j]!=0){
                compact_matrix[0][q]=i;
                compact_matrix[1][q]=j;
                compact_matrix[2][q]=sparseMatrix[i][j];
                q++;        
            }
        }
    }
    printf("\n");
    for(int i=0;i<3;i++){
        if(i==0) printf("Row : ");
        else if(i==1) printf("Column : ");
        else printf("Value : ");
        for(int j=0;j<size;j++){
            printf("%d ",compact_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}