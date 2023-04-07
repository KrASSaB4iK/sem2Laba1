#include <stdio.h>
#include "matrix.h"
#include "matrixint.h"
#include "matrixfloat.h"

void menu(){ 
    printf("Какого типа данных будет матрица\n1 - (int)\n 2- (float)"); 
    int choise = 1;
    Matrix **array = new_array_Matrixs();
    int count; 
    while(choise != 8){ 
        printf("1 - create matrix\n2 - delete matrix\n3 - print matrix\n4 - sum matrix\n5 - mat multiplication\n6 - mat trasposition\n7 - adding to a line\n8 - quit\nenter the number:"); 
        scanf("%d", &choise); 
        switch(choise){ 
            case 1: 
                printf("Какого типа данных будет матрица\n1 - (int)\n 2- (float)");
                array = choose_type_of_matrix(array, &count);
                break; 
            case 2:  
                break; 
            case 3: 
                print_Matrix(choose_Matrix(array, &count)); 
                break; 
            case 4: 
                sum_Matrix(array, &count);
                break; 
            case 5: 
                multi_Matrix(array, &count);
                break; 
            case 6: 
                trans_Matrix(array, &count);
                break; 
            case 7: 
                break; 
        } 
    } 
    delete_array_Matrix(array, &count);
}