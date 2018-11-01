//
//  2.c
//  strassen alg
//
//  Created by wzh on 25/02/2017.
//  Copyright © 2017 wzh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define LENGTH 8
int NUM;

typedef
struct Matrix{
    int **Array;
    int CAR;
    int Value;
}Matrix;

Matrix * SET_RMatrix(int CAR){
    srand((int)time(NULL));
    Matrix *Result = (Matrix *)malloc(sizeof(Matrix));
    //scanf("%d",&Result->CAR);
    Result->Array = (int **)malloc(CAR * sizeof(int *));
    
    for(int i = 0;i < CAR;i++)
        Result->Array[i]=(int *)malloc(sizeof(int) * CAR);//error: use Result->CAR
    
    for(int i = 0;i < CAR;i++){
        for(int j = 0;j < CAR;j++){
            Result->Array[i][j] = rand() % 10;
            //printf("%*d",LENGTH,Result->Array[i][j]);
        }
        //printf("\n");
    }
    Result->CAR = CAR;
    return Result;
}

void PRINT_Matrix (Matrix * N){
    for(int i=0 ;i < N->CAR;i++){
        for(int j=0;j < N->CAR;j++){
            printf("%*d",LENGTH,N->Array[i][j]);
        }
        printf("\n");
    }
}

Matrix * SET_VMatrix(int CAR){
    Matrix *Result = (Matrix *)malloc(sizeof(Matrix));
    Result->Array = (int **)malloc(CAR * sizeof(int *));
    for(int i = 0;i < CAR;i++)
        Result->Array[i]=(int *)malloc(sizeof(int) * CAR);
    
    //printf("Vmatrix set succeed");
    Result->CAR = CAR;
    return Result;
}

void FREE_Matrix(Matrix * p){
    
    for(int i=0;i < p->CAR;i++)
        free(p->Array[i]);
    free(p->Array);
    free(p);
    //printf("free success ");
}


Matrix * ADD_Matrix(Matrix * A,Matrix * B){
    Matrix * FINAL = SET_VMatrix(A->CAR);
    for(int i = 0;i < A->CAR;i++){
        for(int j = 0;j < A ->CAR;j++){
        FINAL->Array[i][j] = A->Array[i][j] + B->Array[i][j];
        }
    }
    return FINAL;
}

Matrix * MINUS_Matrix(Matrix * A,Matrix * B){
    Matrix * FINAL = SET_VMatrix(A->CAR);
    for(int i = 0;i < A->CAR;i++){
        for(int j = 0;j < A ->CAR;j++){
            FINAL->Array[i][j] = A->Array[i][j] - B->Array[i][j];
        }
    }
    return FINAL;
}


Matrix * NAIVE_VALUE_Matrix(Matrix *A , Matrix * B){
    int temp,RowA,RowB,ColA,ColB;
    Matrix * Result = SET_VMatrix(A->CAR);
    
    for(RowA = 0;RowA < A->CAR;RowA++){
        for(ColB = 0;ColB < A->CAR;ColB++){
            for(RowB = 0,ColA = 0,temp = 0;RowB < A->CAR ;RowB++,ColA++){
                temp = temp + (A->Array[RowA][ColA]) * (B->Array[RowB][ColB]);
            }
            Result->Array[RowA][ColB] = temp;
            //printf("%*d",LENGTH,Result->Array[RowA][ColB]);
        }
        //printf("\n");
    }
    
    return Result;
}

Matrix * Strassen(int N,Matrix *A,Matrix *B){
    Matrix *A11,*A12,*A21,*A22,*B11,*B12,*B21,*B22,*C11,*C12,*C21,*C22,*AResult,*BResult,*P1,*P2,*P3,*P4,*P5,*P6,*P7,*MatrixResult;
    A11 = SET_VMatrix(N/2);
    A12 = SET_VMatrix(N/2);
    A21 = SET_VMatrix(N/2);
    A22 = SET_VMatrix(N/2);
    
    B11 = SET_VMatrix(N/2);
    B12 = SET_VMatrix(N/2);
    B21 = SET_VMatrix(N/2);
    B22 = SET_VMatrix(N/2);
    
    C11 = SET_VMatrix(N/2);
    C12 = SET_VMatrix(N/2);
    C21 = SET_VMatrix(N/2);
    C22 = SET_VMatrix(N/2);
    
    AResult = SET_VMatrix(N/2);
    BResult = SET_VMatrix(N/2);
    //MatrixResult = SET_VMatrix(N);
    
    P1 = SET_VMatrix(N/2);
    P2 = SET_VMatrix(N/2);
    P3 = SET_VMatrix(N/2);
    P4 = SET_VMatrix(N/2);
    P5 = SET_VMatrix(N/2);
    P6 = SET_VMatrix(N/2);
    P7 = SET_VMatrix(N/2);
   
    for(int i = 0;i < N/2;i++){
        for(int j = 0;j<N/2;j++){
            A11->Array[i][j] = A->Array[i][j];
            A12->Array[i][j] = A->Array[i][j+N/2];
            A21->Array[i][j] = A->Array[i+N/2][j];
            A22->Array[i][j] = A->Array[i+N/2][i+N/2];
         
            B11->Array[i][j] = B->Array[i][j];
            B12->Array[i][j] = B->Array[i][j+N/2];
            B21->Array[i][j] = B->Array[i+N/2][j];
            B22->Array[i][j] = B->Array[i+N/2][i+N/2];
        }
    }
    
    //recursion
    int HalfSize = N/2;
    if(HalfSize > 2){
    BResult = MINUS_Matrix(B12, B22);
    P1 = Strassen(HalfSize, A11, BResult);
    //P1.
    
    AResult = ADD_Matrix(A11, A12);
    P2 = Strassen(HalfSize, AResult, B22);
    //P2.
    
    AResult = ADD_Matrix(A21, A22);
    P3 = Strassen(HalfSize, AResult, B11);
    //P3.
    
    BResult = MINUS_Matrix(B21, B11);
    P4 = Strassen(HalfSize, A22, BResult);
    //P4.
    
    AResult = ADD_Matrix(A11, A22);
    BResult = ADD_Matrix(B11, B22);
    P5 = Strassen(HalfSize, AResult, BResult);
    //P5.
    
    AResult = MINUS_Matrix(A12, A22);
    BResult = ADD_Matrix(B21, B22);
    P6 = Strassen(HalfSize, AResult, BResult);
    //P6.
    
    AResult = MINUS_Matrix(A11, A21);
    BResult = ADD_Matrix(B11, B12);
    P7 = Strassen(HalfSize, AResult, BResult);
    //P7
    }
    
    else{
        
       MatrixResult = NAIVE_VALUE_Matrix(A, B);
        
        free(A11);
        free(A12);
        free(A21);
        free(A22);
        free(B11);
        free(B12);
        free(B21);
        free(B22);
        free(C11);
        free(C12);
        free(C21);
        free(C22);
        free(P1);
        free(P2);
        free(P3);
        free(P4);
        free(P5);
        free(P6);
        free(P7);
        free(AResult);
        free(BResult);
        

        return MatrixResult;

    }
    
    C11 = ADD_Matrix(ADD_Matrix(P5, MINUS_Matrix(P4, P2)), P6);
    C12 = ADD_Matrix(P1, P2);
    C21 = ADD_Matrix(P3, P4);
    C22 = ADD_Matrix(MINUS_Matrix(P5, P3), MINUS_Matrix(P1, P7));
    
    
    
    for(int i = 0;i<N/2;i++){
        for(int j = 0;j<N/2;j++){
            MatrixResult->Array[i][j] = C11->Array[i][j];
            MatrixResult->Array[i][j+N/2] = C12->Array[i][j];
            MatrixResult->Array[i+N/2][j] = C21->Array[i][j];
            MatrixResult->Array[i+N/2][j+N/2] = C22->Array[i][j];
        }
    }
     
    
    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);
    free(C11);
    free(C12);
    free(C21);
    free(C22);
    free(P1);
    free(P2);
    free(P3);
    free(P4);
    free(P5);
    free(P6);
    free(P7);
    free(AResult);
    free(BResult);
    

   
    return MatrixResult;
   
}




int main(void){
    int NUM;
    double S_Durition,N_Durition;
    printf("ENTER THE DIMENTION 1: ");
    scanf("%d",&NUM);
    Matrix * A = SET_RMatrix(NUM);

    printf("ENTER THE DIMENTION 2: ");
    scanf("%d",&NUM);
    Matrix * B = SET_RMatrix(NUM);
    
    Matrix *C = SET_VMatrix(NUM);
    Matrix *D = SET_VMatrix(NUM);
    printf("\n--------STRASSEN ALGRITHM---------\n");
    
    
    
    clock_t s_start,s_end,n_start,n_end;
    
    n_start = clock();
    D = NAIVE_VALUE_Matrix(A, B);
    n_end = clock();
    
    
    s_start = clock();
    C = Strassen(NUM, A, B);
    s_end = clock();
    
    
    N_Durition = (double)(n_end - n_start)/CLOCKS_PER_SEC;
    S_Durition = (double)(s_end - s_start)/CLOCKS_PER_SEC;
    
    
    printf("\n  Naive  : the runing time is %f seconds\n",N_Durition);
    printf("\nStrassen : the runing time is %f seconds\n",S_Durition);
    
    /*
    printf("TARGET MATRIX 1: \n-------------------------\n");
    PRINT_Matrix(A);

    printf("TARGET MATRIX 2: \n-------------------------\n");
    PRINT_Matrix(B);

    printf("RESULT   MATRIX: \n-------------------------\n");
    PRINT_Matrix(C);
    printf("\n");
    PRINT_Matrix(D);
    */
    
    FREE_Matrix(A);
    FREE_Matrix(B);
    FREE_Matrix(C);
    
    
    return 0;
}


