// array_operations.cpp
#include "array_operations.h"

using namespace std;

// Function to read data from a file and populate the array
void ArrayOperations::readDataFromFile(const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        int value;

        while (file >> value) {
            // Add a new row with the first value
            arrayData.push_back({ value });

            // Read the remaining 9 values for the row
            for (int i = 1; i < 10; ++i) {
                file >> value;
                arrayData.back().push_back(value);
            }
        }

        file.close();
    }
    else {
        cout << "Unable to open the file.\n";
    }
}

// Function to search for a certain integer in the array
int ArrayOperations::searchElement(int value) {
    for (int i = 0; i < arrayData.size(); ++i) {
        for (int j = 0; j < arrayData[i].size(); ++j) {
            if (arrayData[i][j] == value) {
                return i * 10 + j;  // Return the linear index
            }
        }
    }

    return -1;  // Value not found
}

// Function to modify an element at a given index
int ArrayOperations::modifyElement(int index, int newValue) {
    int row = index / 10;
    int col = index % 10;
    int oldValue = arrayData[row][col];
    arrayData[row][col] = newValue;
    return oldValue;
}

// Function to add an element to the array
void ArrayOperations::addElement(int value) {
    int row = arrayData.size() - 1;
    int col = arrayData.back().size();

    if (col == 10) {
        arrayData.push_back({ value });  // Add a new row
    }
    else {
        arrayData[row].push_back(value);  // Append to the current row
    }
}

// Function to replace an element at a given index
void ArrayOperations::replaceElement(int index, int newValue) {
    int row = index / 10;
    int col = index % 10;
    arrayData[row][col] = newValue;
}

// Function to remove an element at a given index
void ArrayOperations::removeElement(int index) {
    int row = index / 10;
    int col = index % 10;
    arrayData[row].erase(arrayData[row].begin() + col);
}

// Function to print the array
void ArrayOperations::printArray() {
    for (const auto& row : arrayData) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}
