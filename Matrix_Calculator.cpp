// Project5.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>


class matrix {
private:
    int rows{};
    int columns{};
    double* matrix_data{ (double*)malloc(rows * columns * sizeof(double)) };
public:
    matrix() = default;

    matrix(int m_rows, int n_columns, double* vector_data) : rows{ m_rows }, columns{ n_columns }, matrix_data{ vector_data }{}
    double* get_data();
    int get_row();
    int get_col();
    matrix operator+(matrix matrix_1);

};

int matrix::get_row() {
    return rows;
}

int matrix::get_col() {
    return columns;
}
double* matrix::get_data() {
    return matrix_data;
}
matrix matrix::operator+(matrix matrix_1) {
    int counter{};
    matrix sum_matrix;
    double* new_data{(double*)malloc(rows * columns * sizeof(double)) };
    double* second_matrix_data{(double*)malloc(rows * columns * sizeof(double)) };
    second_matrix_data = matrix_1.get_data();

    if (rows == matrix_1.get_row() && columns == matrix_1.get_col()) {
        while (new_data) {
            new_data[counter] = matrix_data[counter] + second_matrix_data[counter];
            counter++;
            new_data++;
        }
    }
    sum_matrix = matrix(rows, columns, new_data);
    return sum_matrix;
}

int main()
{
    /*double vec[4] = { 1., 2., 3., 4. };
    matrix mat;

    matrix mat2;

    matrix sum{ mat + mat2 };

    mat = matrix(2, 2, &vec[0]);

    mat2 = matrix(2, 2, &vec[0]);

    std::cout << "The number of columns is " ;*/
    

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
