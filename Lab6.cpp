#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
//Need to include vectors and sstream for the work i want to do


//Rubric requires prototyping, so I did that here
//Majority of functions return 2d arrays, one is designed just to print 
void printMatrix(const std::vector<std::vector<int> >& inputMatrix);
std::pair<std::vector<std::vector<int> >, std::vector<std::vector<int> > > separateMatrix(const std::vector<std::vector<int> >& inputMatrix, int n);
std::vector<std::vector<int> > addMatrix(const std::vector<std::vector<int> >& matrix1, const std::vector<std::vector<int> >& matrix2);
std::vector<std::vector<int> > multiplyMatrix(const std::vector<std::vector<int> >& matrix1, const std::vector<std::vector<int> >& matrix2);
std::vector<std::vector<int> > subtractMatrix(const std::vector<std::vector<int> >& matrix1, const std::vector<std::vector<int> >& matrix2);

int main() {
    //Create an input for in-filestream called input file, and a string name where user can input file they want read
    std::ifstream inputFile;
    std::string userFile;
    std::vector<std::vector<int> > twoDList;

    std::cout << "Enter the name of the file you want read: ";
    std::cin >> userFile;
    std::cout << "\n";

    inputFile.open(userFile);

    //Declare j which will be the nxn matrix we read
    int j;
    std::string line;
    //Read the very first line in, and then effectively make it so we can't read it into future arrays; store it tho
    if (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        if (iss >> j) {
        }
    }
    //Loop through file and for each item, append it to the two dimensional list I made
    while (std::getline(inputFile, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int item;

            while (iss >> item) {
                row.push_back(item);
            }

        twoDList.push_back(row);
    }
    //Declare all the vector types we're going to need for printing, vectors of vectors containing ints, self explanatory
    std::vector<std::vector<int> > matrix1;
    std::vector<std::vector<int> > matrix2;
    std::vector<std::vector<int> > matrixsum;
    std::vector<std::vector<int> > matrixproduct;
    std::vector<std::vector<int> > matrixdifference;

    // Call the separateMatrix function and receive the result
    std::pair<std::vector<std::vector<int> >, std::vector<std::vector<int> > > result = separateMatrix(twoDList, j);

    // Assign the results to matrix1 and matrix2
    matrix1 = result.first;
    matrix2 = result.second;

    //Print what is required to make the program well formatted
    //This includes function calls, and statements out
    std::cout << "Aidan Ingram\n";
    std::cout << "Lab #6: Matrix manipulation\n\n";

    std::cout << "Matrix A:\n";
    printMatrix(matrix1);
    std::cout << "\n";
    std::cout << "Matrix B:\n";
    printMatrix(matrix2);
    std::cout << "\n";
    std::cout << "Matrix Sum (A + B):\n";
    matrixsum = addMatrix(matrix1, matrix2);
    printMatrix(matrixsum);
    std::cout << "\n";
    std::cout << "Matrix Product (A * B):\n";
    matrixproduct = multiplyMatrix(matrix1, matrix2);
    printMatrix(matrixproduct);
    std::cout << "\n";
    std::cout << "Matrix Difference (A - B):\n";
    matrixdifference = subtractMatrix(matrix1, matrix2);
    printMatrix(matrixdifference);
    std::cout << "\n";

    //Important to close file, so make sure to do that when it's all done
    inputFile.close();
    return 0;
}

//Function that will return a pair of two dimensional vectors, takes the original one in to separate it
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
    //Creating the second matrix
    for (int i = n; i < inputMatrix.size(); ++i) {
        for (size_t j = 0; j < inputMatrix[i].size(); ++j) {
            matrix2[i - n][j] = inputMatrix[i][j];
        }
    }
return std::make_pair(matrix1, matrix2);
}

//Function that prints a matrix passed in, takes a 2d vector
void printMatrix(const std::vector<std::vector<int> >& inputMatrix) {
    for (size_t i = 0; i < inputMatrix.size(); ++i) {
    for (size_t j = 0; j < inputMatrix[i].size(); ++j) {
        std::cout << inputMatrix[i][j] << " ";
    }
    std::cout << std::endl;
}
}

//Add matrix, returns a new 2d vector and takes two in as parameter
std::vector<std::vector<int> > addMatrix(const std::vector<std::vector<int> >& matrix1, const std::vector<std::vector<int> >& matrix2) {
    //Initialize rows and columns
    int numRows = matrix1.size();
    int numCols = matrix1[0].size();

    //Initialize new matrix
    std::vector<std::vector<int> > newmatrix(numRows, std::vector<int>(numCols, 0));

    //Iterate through and add items in matrices
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            newmatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return newmatrix;
}

//Rubric actually wants cross product for matrix multiplication, so do that here
std::vector<std::vector<int> > multiplyMatrix(const std::vector<std::vector<int> >& matrix1, const std::vector<std::vector<int> >& matrix2) {
    //Initialize rows for the first matrix, and cols, but just cols for the second
    int numRowsA = matrix1.size();
    int numColsA = matrix1[0].size();
    int numColsB = matrix2[0].size();

    std::vector<std::vector<int> > newmatrix(numRowsA, std::vector<int>(numColsB, 0));

    //Iterate through the three iterables we have and multiply the result; add to new matrix
    for (int i = 0; i < numRowsA; i++) {
        for (int j = 0; j < numColsB; j++) {
            for (int k = 0; k < numColsA; k++) {
                newmatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return newmatrix;
}

//Subtract indices and add the result to a new matrix
std::vector<std::vector<int> > subtractMatrix(const std::vector<std::vector<int> >& matrix1, const std::vector<std::vector<int> >& matrix2) {
    //Initialize rows and columns
    int numRows = matrix1.size();
    int numCols = matrix1[0].size();

    std::vector<std::vector<int> > newmatrix(numRows, std::vector<int>(numCols, 0));

    //Same as addition function, iterate through and subtract this time
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            newmatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return newmatrix;
}