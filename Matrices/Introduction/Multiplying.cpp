// Building a project that multiple a matrix
#include <vector>
#include <iostream>

using Matrix = std::vector<std::vector<float>>;

int main()
{
    float Number;
    Matrix matrix = {
        {1, 1 ,1},
        {1, 1, 1},
        {1, 1, 1}
    };

    Matrix new_matrix;
    
    std::cout << "Select a Number: ";
    std::cin >> Number;

    for (size_t each_column = 0; each_column < matrix.size(); each_column++) {
        for (size_t each_number = 0; each_number < matrix[each_column].size(); each_number++) {
            matrix[each_column][each_number] *= Number;
            new_matrix.push_back(matrix[each_column]);
        }
    }
    std::cout << "New Matrix value: \n";

    for (const auto& row : new_matrix) {    
        for (auto& element : row) {
        std::cout << element << "";
        }
        std::cout << std::endl;
    }
}