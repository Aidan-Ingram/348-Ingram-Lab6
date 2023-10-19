#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>



std::pair<std::vector<std::vector<int> >, std::vector<std::vector<int> > > separateMatrix(const std::vector<std::vector<int> >& inputMatrix, int n) {
    // Check if the input matrix contains enough rows
    if (inputMatrix.size() % n != 0) {
        std::cerr << "Your input is lopsided; ensure your total lines / 2 = your n." << std::endl;
        return std::make_pair(std::vector<std::vector<int> >(), std::vector<std::vector<int> >());
    }
    std::vector<std::vector<int> > matrix1;
    std::vector<std::vector<int> > matrix2;
    // Initialize the resulting matrices with the same number of columns
    matrix1 = std::vector<std::vector<int> >(n, std::vector<int>(inputMatrix[0].size()));
    matrix2 = std::vector<std::vector<int> >(inputMatrix.size() - n, std::vector<int>(inputMatrix[0].size()));

    // Copy the first n rows into matrix1 and the remaining rows into matrix2
    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < inputMatrix[i].size(); ++j) {
            matrix1[i][j] = inputMatrix[i][j];
        }
    }

    for (int i = n; i < inputMatrix.size(); ++i) {
        for (size_t j = 0; j < inputMatrix[i].size(); ++j) {
            matrix2[i - n][j] = inputMatrix[i][j];
        }
    }
return std::make_pair(matrix1, matrix2);
}

void printMatrix(const std::vector<std::vector<int> >& inputMatrix) {
    for (size_t i = 0; i < inputMatrix.size(); ++i) {
    for (size_t j = 0; j < inputMatrix[i].size(); ++j) {
        std::cout << inputMatrix[i][j] << " ";
    }
    std::cout << std::endl;
}
}

std::vector<std::vector<int> > addMatrix(const std::vector<std::vector<int> >& matrix1, const std::vector<std::vector<int> >& matrix2) {
    std::vector<std::vector<int> > newmatrix;
}

int main() {
    std::ifstream inputFile;
    std::string userFile;
    std::vector<std::vector<int> > twoDList;

    std::cout << "Enter the name of the file you want read: ";
    std::cin >> userFile;

    inputFile.open(userFile);

    int j;
    std::string line;
    if (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        if (iss >> j) {
        }
    }
    while (std::getline(inputFile, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int item;

            while (iss >> item) {
                row.push_back(item);
            }

        twoDList.push_back(row);
    }
    std::cout << j;
    std::vector<std::vector<int> > matrix1;
    std::vector<std::vector<int> > matrix2;

    // Call the separateMatrix function and receive the result
    std::pair<std::vector<std::vector<int> >, std::vector<std::vector<int> > > result = separateMatrix(twoDList, j);

    // Assign the resulting matrices to matrix1 and matrix2
    matrix1 = result.first;
    matrix2 = result.second;

    std::cout << "Aidan Ingram\n";
    std::cout << "Lab #6: Matrix manipulation\n\n";

    std::cout << "Matrix A:\n";
    printMatrix(matrix1);
    std::cout << "Matrix B:\n";
    printMatrix(matrix2);
    std::cout << "Matrix Sum (A + B):\n";

    std::cout << "Matrix Product (A * B):\n";

    std::cout << "Matrix Difference (A - B):/n";


    inputFile.close();
    return 0;
}



