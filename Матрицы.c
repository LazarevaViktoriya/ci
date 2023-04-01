//Написать программу, которая запрашивает у пользователя размер матрицы, заполняет ее случайными числами и выводит на экран. Затем программа должна находить наибольший элемент в каждой строке и находить их среднее значение.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);
    
    int matrix[rows][cols];
    srand(time(NULL));
    
    // Заполнение матрицы случайными числами
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    // Вывод матрицы на экран
    printf("Матрица:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Нахождение наибольшего элемента в каждой строке
    int max[rows];
    for(int i = 0; i < rows; i++) {
        max[i] = matrix[i][0];
        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] > max[i]) {
                max[i] = matrix[i][j];
            }
        }
    }
    
    // Нахождение среднего значения наибольших элементов
    int sum = 0;
    for(int i = 0; i < rows; i++) {
        sum += max[i];
    }
    double average = (double)sum / rows;
    
    printf("Наибольшие элементы в каждой строке:\n");
    for(int i = 0; i < rows; i++) {
        printf("%d ", max[i]);
    }
    printf("\n");
    printf("Среднее значение наибольших элементов: %.2f\n", average);
    
    return 0;
}
