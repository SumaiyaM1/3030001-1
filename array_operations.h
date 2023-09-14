#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ArrayOperations {
public:
    // Read data from a file into the 2D array
    void readDataFromFile(const string& filename);

    // Search for a value in the array
    // Returns the index of the first occurrence
    int searchElement(int value);

    // Modify the value at index and return the old value
    // Returns -1 if the index is not ava.
    int modifyElement(int index, int newValue);

    // Add an element to the end of the array
    void addElement(int value);

    // Replace the value at index with a new value
    // Does nothing if the index is out of bounds
    void replaceElement(int index, int newValue);

    // Remove the element at index
    // Does nothing if the index is out of bounds
    void removeElement(int index);

    // Print the contents of the 2D array
    void printArray();

private:
    vector<vector<int>> arrayData;
};

#endif
