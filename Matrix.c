#include<stdio.h>
float newMatrix[4][4];
void normalizeMatrix(int rowSize, int colSize, float mat[rowSize][colSize]){
    float max = 0;
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<colSize; j++){
            if(mat[i][j] > max){
                max = mat[i][j];
            }
        }
    }
    //changing the values of odd columns by diving the highest with the old column value
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<colSize; j++){
            if(j == 1 || j == 3){
                newMatrix[i][j] = mat[i][j]/max;
            }
            else{
                newMatrix[i][j] = mat[i][j];
            }
        }
    }
}
void printMatrix(int rowSize, int colSize, float newMatrix[rowSize][colSize]){
    for(int i=0; i<rowSize; i++){
        for(int j=0; j<colSize; j++){
            printf(" %.2f ", newMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int colSize = 4, rowSize = 4;
    float mat[4][4] = {{2.3, 4.5, 3.3, 4.4}, {2.2, 4.3, 5.7, 6.8}, {9.0, 8.8, 7.3, 3.3,}, {2.5, 6.7, 4.5, 7.7}};
    normalizeMatrix (rowSize, colSize, mat);
    printMatrix(rowSize, colSize, newMatrix);
}
