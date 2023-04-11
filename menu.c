#include <stdio.h>
#include "matrix.h"
#include "matrixint.h"
#include "matrixfloat.h"

void menu(){ 
    printf("Какого типа данных будет матрица\n1 - (int)\n 2- (float)"); 
    int choise = 1;
    Matrix **array = new_array_Matrixs();
    int count = 0; 
    while(choise != 8){ 
        printf("1 - create matrix\n2 - sum matrix\n3 - minus matrix\n4 - multi matrix\n5 - print matrix\n6 - mat trasposition\n7 - adding to a line\n8 - quit\nenter the number:"); 
        scanf("%d", &choise); 
        switch(choise){ 
            case 1: 
                printf("Какого типа данных будет матрица\n1 - (int)\n 2- (float)");
                array = choose_type_of_matrix(array, &count);
                break; 
            case 2:  
                array = sum_Matrix(array, &count);
                break; 
            case 3: 
                array = minus_Matrix(array, &count);
                break; 
            case 4: 
                array = multi_Matrix(array, &count);
                break; 
            case 5: 
                print_Matrix(choose_Matrix(array, &count)); 
                break; 
            case 6: 
                array = trans_Matrix(array, &count);
                break; 
            case 7: 
                array = add_line_to_line(array, &count);
                break; 
        } 
    } 
    delete_array_Matrix(array, &count);
}
