#include<stdio.h>
#define max_size 10

void menu(){
    printf("Matrix Operations Menu:\n1. Input Matrices\n2. Add Matrices\n3. Subtract Matrices\n4. Multiply Matrices\n5. Transpose Matrix\n6. Determinant of Matrix\n7. Inverse of Matrix\n8. Trace of Matrix\n9. Check Symmetric Matrix\n10. Display Matrices\n11. Exit\nEnter your choice: ");
}

void matrix_input(int row,int col,int a[max_size][max_size]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void matrix_output(int row, int col, int a[max_size][max_size]){
    printf("Matrix (%dx%d):\n",row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void matrix_output_inv(int row, int col, float a[max_size][max_size]){
    printf("Matrix (%dx%d):\n",row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%.2f ",a[i][j]);
        }
        printf("\n");
    }
}

void matrix_sum(int row,int col,int a[max_size][max_size],int b[max_size][max_size],int c[max_size][max_size]){
    printf("\nSummation of matrix:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}

void matrix_subtract(int row,int col,int a[max_size][max_size],int b[max_size][max_size],int c[max_size][max_size]){
    printf("\nSubtraction of matrix:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            c[i][j]=a[i][j]-b[i][j];
        }
    }
}

void matrix_multiplication(int row1,int col1,int col2,int a[max_size][max_size],int b[max_size][max_size],int c[max_size][max_size]){
    printf("\nmultiplication of matrix:\n");
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            c[i][j]=0;
            for(int k=0;k<col1;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

int matrix_trace(int row,int col,int a[max_size][max_size]){
    int sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==j){
                sum+=a[i][j];
            }
        }
    }
    return sum;
    
}

int matrix_determinant(int n, int det[max_size][max_size]){
    if (n == 1){
        return det[0][0];
    }
    if(n == 2){
        return det[0][0] * det[1][1] - det[0][1] * det[1][0];
    }
    int value = 0;
    int sub_det[max_size][max_size];


    for(int i = 0; i < n; i++){
        int sign = (i % 2 == 0) ? 1 : -1;
        
        for(int r = 1; r < n;r++){
            int curr_col = 0;
            for(int c = 0; c < n; c++){
                if(c == i){
                    continue;
                }
                sub_det[r - 1][curr_col] = det[r][c];
                curr_col++;  
            }
        }
        value += sign * det[0][i] * matrix_determinant(n - 1, sub_det);
    }

    return value;
}
void Cofactor(int sR, int sC, int size,int a[max_size][max_size], int cof[max_size][max_size]) {
    int row = 0, col = 0;

    for (int i = 0; i < size; i++) {
        if (i == sR) continue;

        col = 0;
        for (int j = 0; j < size; j++) {
            if (j == sC) continue;

            cof[row][col++] = a[i][j];
        }
        row++;
    }
}
void Adjoint(int i, int j,int n,int mat[max_size][max_size], int adj[max_size][max_size]) {
    if (i == n) return;

    if (j == n) {
        Adjoint(i + 1, 0,n,mat, adj);
        return;
    }

    int minor[max_size][max_size];
    Cofactor(i, j, n,mat, minor);
    int sign = ((i + j) % 2 == 0) ? 1 : -1;
    adj[j][i] = sign * matrix_determinant(n - 1,minor);

    Adjoint(i, j + 1,n,mat, adj);
}
void divByDeterminant(int i, int j, int n,int det,int adjoint[max_size][max_size], float inverse[max_size][max_size]) {
    if (i == n) return;

    if (j == n) {
        divByDeterminant(i + 1, 0,n,det,adjoint, inverse);
        return;
    }

    inverse[i][j] = (float)adjoint[i][j] / det;
    divByDeterminant(i, j + 1,n,det,adjoint, inverse);
}
int Inverse(int n,int mat[max_size][max_size], float inv[max_size][max_size]) {
    int det = matrix_determinant(n,mat);

    if (det > -1e-6 && det < 1e-6) { 
    return 0;
}

    int adjoint[max_size][max_size];
    Adjoint(0, 0,n,mat, adjoint);
    divByDeterminant(0, 0,n,det,adjoint, inv);

    return 1;
}

void matrix_transpose(int row,int col,int a[max_size][max_size],int tran[max_size][max_size]){
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
             tran[j][i]=a[i][j];   
        }
    }
    
}
int matrix_symmetry(int row,int col,int mat[max_size][max_size]){
    int temp[max_size][max_size];
    matrix_transpose(row,col,mat,temp);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]!=temp[i][j])
            return 0;
        }
    }
    return 1;   
}

int main()
{
    int mat1[max_size][max_size],mat2[max_size][max_size],result[max_size][max_size];
    float mat_r[max_size][max_size];
    int row1=0,col1=0,row2=0,col2=0;
    int x;
    while(1){
        menu();
        scanf("%d",&x);
        switch (x)
    {
    case 1:{
        printf("Enter number of rows for matrix A (max 10): ");
        scanf("%d",&row1); 
        printf("Enter number of columns for matrix A (max 10): ");
        scanf("%d",&col1);
        
        if((row1>0&&row1<11)&&(col1>0&&col1<11)){
            printf("Enter elements of matrix A (%dx%d):\n",row1,col1);
            matrix_input(row1,col1,mat1);
        }
        else printf("\nThis order of the matrix isn't acceptable.\n\n");
        
        printf("Enter number of rows for matrix B (max 10): ");
        scanf("%d",&row2); 
        printf("Enter number of columns for matrix B (max 10): ");
        scanf("%d",&col2);
        
        if((row2>0&&row2<11)&&(col2>0&&col2<11)){
            printf("Enter elements of matrix B (%dx%d):\n",row2,col2);
            matrix_input(row2,col2,mat2);
        }
        else printf("\nThis order of the matrix isn't acceptable.\n\n");
        break;
    }
    case 2:
        if(row1==row2 && col1==col2){
            matrix_sum(row1,col1,mat1,mat2,result);
            matrix_output(row1,col1,result);
            printf("\n\n");
        }
        else printf("\nsummation can't be done as their order isn't same.\n\n");
        break;
    case 3:
        if(row1==row2 && col1==col2){
            matrix_subtract(row1,col1,mat1,mat2,result);
            matrix_output(row1,col1,result);
            printf("\n\n");
        }
        else printf("\nsubtraction can't be done as their order isn't same.\n\n");
        break;
    case 4:
        if(col1==row2){
            matrix_multiplication(row1,col1,col2,mat1,mat2,result);
            matrix_output(row1,col2,result);
            printf("\n\n");
        }
        else printf("\nMultiplication doesn't exist.\n\n");
        break;  
    case 5:
        if(row1==col1){
            printf("\nTranspose of Matrix A:\n");
            matrix_transpose(row1,col1,mat1,result);
            matrix_output(row1,col1,result);
            printf("\n\n");
        }
        else{
            printf("\nA isn't a square matrix.\n\n");
        }
        if(row2==col2){
            printf("\nTranspose of Matrix B:\n");
            matrix_transpose(row2,col2,mat2,result);
            matrix_output(row2,col2,result);
            printf("\n\n");
        }
        else{
            printf("\nB isn't a square matrix.\n\n");
        }
        break;
    case 6:
        printf("\nDeterminant of which matrix? (A/B): ");
        char mt;
        scanf(" %c",&mt);
        if(mt=='A'){
            if(row1==col1){
                int determinant=matrix_determinant(row1,mat1);
                printf("\nDeterminant of Matrix A is %d\n\n",determinant);
            }
            else printf("\nA isn't a square matrix.\n\n");
        }
        else if(mt=='B'){
            if(row2==col2){
                int determinant=matrix_determinant(row2,mat2);
                printf("\nDeterminant of Matrix B is %d\n\n",determinant);
            }
            else printf("\nB isn't a square matrix.\n\n");
        }
        else printf("\nNo such matrix exist.\n\n");
        break;
    case 7:
        printf("\nInverse of which matrix? (A/B): ");
        char m;
        scanf(" %c",&m);
        if(m=='A'){
            if(row1==col1){
                int res=Inverse(row1,mat1,mat_r);
                if(res){
                    printf("Inverse of Matrix A:\n");
                    matrix_output_inv(row1,col1,mat_r);
                    printf("\n\n");
                }
                else printf("\nInverse is not possible.\n\n");
               
            }
            else printf("\nA isn't a square matrix.\n\n");
        }
        else if(m=='B'){
            if(row2==col2){
                int res=Inverse(row2,mat2,mat_r);
                if(res){
                    printf("Inverse of Matrix B:\n");
                    matrix_output_inv(row2,col2,mat_r);
                    printf("\n\n");
                }
                else printf("\nInverse is not possible.\n\n");
               
            }
            else printf("\nB isn't a square matrix.\n\n");
        }
        else printf("\nNo such matrix exist.\n\n");
        break;
    case 8:
        printf("\nTrace of which matrix? (A/B): ");
        char t;
        scanf(" %c",&t);
        if(t=='A'){
            if(row1==col1){
                int res=matrix_trace(row1,col1,mat1);
                printf("\nTrace of Matrix A is %d\n\n",res);
               
            }
            else printf("\nA isn't a square matrix.\n\n");
        }
        else if(t=='B'){
            if(row2==col2){
                int res=matrix_trace(row2,col2,mat2);
                printf("\nTrace of Matrix B is %d\n\n",res);
            }
            else printf("\nB isn't a square matrix.\n\n");
        }
        else printf("\nNo such matrix exist.\n\n");
        break;
    case 9:
        printf("\nCheck symmetric for which matrix? (A/B): ");
        char p;
        scanf(" %c",&p);
        if(p=='A'){
            if(row1==col1){
                int res=matrix_symmetry(row1,col1,mat1);
                if(res){
                    printf("\nMatrix A is symmetric.\n\n");
                }
                else printf("\nMatrix A is not symmetric.\n\n");
            }
            else printf("\nA isn't a square matrix.\n\n");
        }
        else if(p=='B'){
            if(row2==col2){
                int res=matrix_symmetry(row2,col2,mat2);
                if(res){
                    printf("\nMatrix B is symmetric.\n\n");
                }
                else printf("\nMatrix B is not symmetric.\n\n");
            }
            else printf("\nB isn't a square matrix.\n\n");
        }
        else printf("\nNo such matrix exist.\n\n");
        break;
    case 10:
        printf("\nMatrix A:\n");
        matrix_output(row1,col1,mat1);
        printf("\nMatrix B:\n");
        matrix_output(row2,col2,mat2);
        printf("\n");
        break;
    case 11:
    printf("\nExiting program. Thank you.\n\n");
        return 0;
    
    default:
        break;
    }
    }   
}