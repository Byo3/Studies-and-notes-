#include <iostream>
#include <vector>
#include <string>

using matrix = std::vector<double>;

struct Matrix
{
    const int countigRows(std::vector<matrix> Matrix)
    {
        if (Matrix.empty()) {
            std::cout << "\033[1;31mThe matrix is invalid\033[m\n";
            return -1;
        } else {
            return Matrix.size();
        }
    }

    const int countingColunms(std::vector<matrix> Matrix)
    {
        int row_reference = Matrix[0].size();
        // std::cout << row_reference;
        for (const auto &row : Matrix)
        {
            if (row.empty()) 
            {
                std::cout << "\033[1;31mThe matrix is invalid because it's empty\033[m\n";
                return -1;
            }  if (row.size() < row_reference) 
            {
                std::cout << "\033[1;31mThe matrix is invalid\033[m\n";
                return -1;
            }
        }
        return row_reference;
    }
    void matrixDimension(std::vector<matrix> Matrix)
    {
        std::cout << "Matrix dimension: " << countigRows(Matrix)
        << "x" << countingColunms(Matrix) << "\n";
    }
};

struct TranposeMatrix : Matrix
{
    std::vector<double> Matrix_1D(std::vector<matrix> &matrix_input)
    {
        // It pass every elements that are inside of rows, which are vector
        // to a just a sigle vector containing all of the elements
        std::vector<double> matrix_t;
        for (size_t i = 0; i < matrix_input.size(); i++)
        {
            for (size_t j = 0; j < matrix_input[i].size(); j++)
            {
                matrix_t.push_back(matrix_input[i][j]);
            }
        }
        return matrix_t;
    }
    std::vector<matrix> transposingMatrix(std::vector<matrix> &matrix_input)
    {
        std::vector<matrix> new_matrix;
        std::vector<double> given_matrix = Matrix_1D(matrix_input);
        int matrix_column_range = matrix_input[0].size();
        int matrix_range = matrix_input.size();

        for (size_t i = 0; i < matrix_column_range; i++)
        {
            std::vector<double> temporary_row;
            for (size_t j = 0; j < matrix_range; j++)
            {
                int position = (j * matrix_column_range) + i;
                temporary_row.push_back(given_matrix[position]);
            }
           new_matrix.push_back(temporary_row);
        }
        return new_matrix;
    }
};
struct Multiplying : Matrix
{
    TranposeMatrix Transpose;
    const bool validOperations(std::vector<matrix>& arr1, std::vector<matrix>& arr2)
    {
        if (countingColunms(arr1) != countigRows(arr2))
        {
            return true;
        } else 
        {
            return false;
        }
    }

    std::vector<matrix> multiplyingMatrices(std::vector<matrix>& arr1, std::vector<matrix>& arr2)
    {
        if (validOperations(arr1, arr2)) 
        {
            std::cout << "\033[1;31mThe operation is not posibles\033[m ⛔\n";
            return {};
        }
        std::cout << "\033[1;32m The operation is possible\033[m ✅\n"
        << "The new dimension: " << countigRows(arr1) << " x " << countingColunms(arr2) << "\n"; 

        std::vector<matrix> new_matrix;

        std::vector<matrix> transported_arr2 = Transpose.transposingMatrix(arr2);

        for (auto& row_of_arr1 : arr1)
        {
            std::vector<double> temporary_row;
            for (auto column_of_arr2 : transported_arr2)
            {
                double element_result = 0;
                for(size_t elements = 0; elements < column_of_arr2.size(); elements++)
                {
                    element_result += row_of_arr1[elements] * column_of_arr2[elements];
                }
                temporary_row.push_back(element_result);
            }
            new_matrix.push_back(temporary_row);
        }
        return new_matrix;
    }
};

int main()
{
    std::vector<matrix> arr1 {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3}
    };
    std::vector<matrix> arr2 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {1, 0, 1}
    };
    TranposeMatrix Matrix;

    Multiplying Multiply;
    // First matrix
    Matrix.matrixDimension(arr1);
    // Second matrix
    Matrix.matrixDimension(arr2);

    std::vector<matrix> TranposedMatrix = Matrix.transposingMatrix(arr1);

    for (size_t i = 0; i < TranposedMatrix.size(); i++)
    {
        for (size_t j = 0; j < TranposedMatrix[i].size(); j++)
        {
            std::cout << TranposedMatrix[i][j] << ", ";
        }
    }

    std::vector arr3 = Multiply.multiplyingMatrices(arr1, arr2);
    for (size_t i = 0; i < arr3.size(); i++)
    {
        for (size_t j = 0; j < arr3[i].size(); j++)
        {
            std::cout << arr3[i][j] << ", ";
        }
    }
}
