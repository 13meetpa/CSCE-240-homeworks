#include <iostream>
#include "find_sum.h"

const size_t** FindSum(const int** matrix, const size_t* matrix_size, int search_sum, size_t* sums_found) {
    *sums_found = 0;
    size_t** coordinates = new size_t*[4];
    for (size_t i = 0; i < 4; ++i) {
        coordinates[i] = new size_t[4];
    }
    
    for (size_t i = 0; i < matrix_size[0]; ++i) {
        for (size_t ii = 0; ii < matrix_size[1]; ++ii) {
            if (SearchSingleResult(matrix, matrix_size, search_sum, i, ii, coordinates, sums_found)) {
                break;
            }
            SearchRow(matrix, matrix_size, search_sum, i, ii, coordinates, sums_found);
            SearchCol(matrix, matrix_size, search_sum, i, ii, coordinates, sums_found);
            SearchAscDiag(matrix, matrix_size, search_sum, i, ii, coordinates, sums_found);
            SearchDscDiag(matrix, matrix_size, search_sum, i, ii, coordinates, sums_found);
        }
    }
    return const_cast<const size_t**>(coordinates);
}

void SearchRow(const int** matrix, const size_t* matrix_size, int search_sum, size_t currRow, size_t currCol, size_t **coordinates, size_t* sums_found) {
    int sum = 0;
    for (size_t i = currCol; i < matrix_size[1]; ++i) {
        sum += matrix[currRow][i];
        if (sum == search_sum) {
            if (*sums_found >= 4) {
                coordinates = growArray(coordinates, sums_found);
            }
            coordinates[*sums_found][0] = currRow;
            coordinates[*sums_found][1] = currCol;
            coordinates[*sums_found][2] = currRow;
            coordinates[*sums_found][3] = i;
            *sums_found += 1;
        }
    }
}

void SearchCol(const int** matrix, const size_t* matrix_size, int search_sum, size_t currRow, size_t currCol, size_t **coordinates, size_t* sums_found) {
    int sum = 0;
    for (size_t i = currRow; i < matrix_size[0]; ++i) {
        sum += matrix[i][currCol];
        if (sum == search_sum) {
            if (*sums_found >= 4) {
                coordinates = growArray(coordinates, sums_found);
            }
            coordinates[*sums_found][0] = currRow;
            coordinates[*sums_found][1] = currCol;
            coordinates[*sums_found][2] = i;
            coordinates[*sums_found][3] = currCol;
            *sums_found += 1;
        }
    }
}

void SearchAscDiag(const int** matrix, const size_t* matrix_size, int search_sum, size_t currRow, size_t currCol, size_t **coordinates, size_t* sums_found) {
    int sum = 0;
    for (size_t row = currRow, col = currCol; row < matrix_size[0] && col < matrix_size[1]; --row, ++col) {
        sum += matrix[row][col];
        if (sum == search_sum) {
            if (*sums_found >= 4) {
                coordinates = growArray(coordinates, sums_found);
            }
            coordinates[*sums_found][0] = currRow;
            coordinates[*sums_found][1] = currCol;
            coordinates[*sums_found][2] = row;
            coordinates[*sums_found][3] = col;
            *sums_found += 1;
        }
    }
}

void SearchDscDiag(const int** matrix, const size_t* matrix_size, int search_sum, size_t currRow, size_t currCol, size_t **coordinates, size_t* sums_found) {
    int sum = 0;
    for (size_t row = currRow, col = currCol; row < matrix_size[0] && col < matrix_size[1]; --row, --col) {
        sum += matrix[row][col];
        if (sum == search_sum) {
            if (*sums_found >= 4) {
                coordinates = growArray(coordinates, sums_found);
            }
            coordinates[*sums_found][0] = row;
            coordinates[*sums_found][1] = col;
            coordinates[*sums_found][2] = currRow;
            coordinates[*sums_found][3] = currCol;
            *sums_found += 1;
        }
    }
}

bool SearchSingleResult(const int** matrix, const size_t* matrix_size, int search_sum, size_t currRow, size_t currCol, size_t **coordinates, size_t* sums_found) {
    int sum = matrix[currRow][currCol];
    if (sum == search_sum) {
        if (*sums_found >= 4) {
            coordinates = growArray(coordinates, sums_found);
        }
        coordinates[*sums_found][0] = currRow;
        coordinates[*sums_found][1] = currCol;
        coordinates[*sums_found][2] = currRow;
        coordinates[*sums_found][3] = currCol;
        *sums_found += 1;
        return true;
    }
    return false;
}

size_t** growArray(size_t **coordinates, size_t* sums_found) {
    size_t **tmp_array = new size_t*[*sums_found * 2];
    for (size_t i = 0; i < *sums_found; ++i) {
        tmp_array[i] = new size_t[4];
        for (size_t ii = 0; ii < 4; ++ii) {
            tmp_array[i][ii] = coordinates[i][ii];
        }
        delete [] coordinates[i];
    }
    delete [] coordinates;
    *sums_found *= 2;
    return tmp_array;
}
