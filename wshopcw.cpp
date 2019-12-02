#include <vector>
#include <iostream>
#include <unordered_set>

std::vector<int> delete_zeroes(std::vector<int> vec) {
    int new_index = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != 0) {
            vec[new_index] = vec[i];
            new_index++;
        }
    }
    vec.resize(new_index);
    return vec;
}

void delete_col(std::vector<std::vector<int>> matrix) {
    std::unordered_set<int> col;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                col.insert(j);
            }
        }
    }

    for (int elem : col) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i].erase(matrix[i].begin()+elem);
        }
    }
}
