#include <iostream>
#include "array_operations.h"
#include <limits>

using namespace std;

int main() {
    ArrayOperations arrayOps;

    // Step 1: Read data from file into the array
    arrayOps.readDataFromFile("data.txt");

    cout << "Array Data:\n";
    arrayOps.printArray(); // Print the array data
    cout << endl;

    int searchValue;
    bool validInput = false;

    // Step 2: Search for a value in the array
    while (!validInput) {
        try {
            cout << "Enter a value to search in the array: ";
            cin >> searchValue; // Get the value to search for
            cout << endl;

            int searchIndex = arrayOps.searchElement(searchValue); 

            // Display the result of the search
            if (searchIndex != -1) {
                cout << "Value " << searchValue << " found at index " << searchIndex << endl;
                validInput = true; // Break out of the loop if the input is valid
            }
            else {
                cout << "Value " << searchValue << " not found in the array. Please try again..\n";
                cin >> searchValue;
            }

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    int modifyIndex;
    validInput = false;

    // Step 3: Modify an element in the array
    while (!validInput) {
        try {
            cout << "Enter an index to modify an element: ";
            cin >> modifyIndex; // Get the index to modify
            cout << endl;

            int modifyNewValue;
            cout << "Enter the new value: ";
            cin >> modifyNewValue; // Get the new value
            cout << endl;

            int oldValue = arrayOps.modifyElement(modifyIndex, modifyNewValue); 

            // Display the result of the modification
            cout << "Modified value at index " << modifyIndex << ". Old value: " << oldValue
                << ", New value: " << arrayOps.modifyElement(modifyIndex, modifyNewValue) << std::endl;

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    int addValue;
    validInput = false;

    // Step 4: Add a value to the array
    while (!validInput) {
        try {
            cout << "Enter a value to add to the array: ";
            cin >> addValue; // Get the value to add
            cout << endl;

            arrayOps.addElement(addValue); 

            // Display the result of the addition
            cout << "Added value " << addValue << " to the array.\n";

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    int replaceIndex;
    validInput = false;

    // Step 5: Replace an element in the array
    while (!validInput) {
        try {
            cout << "Enter an index to replace an element: ";
            cin >> replaceIndex;
            cout << endl;
            int replaceValue;
            cout << "Enter the new value: ";
            cin >> replaceValue; // Get the new value
            cout << endl;

            arrayOps.replaceElement(replaceIndex, replaceValue); 

            // Display the result of the replacement
            cout << "Replaced value at index " << replaceIndex << " with " << replaceValue << ".\n";

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    int removeIndex;
    validInput = false;

    // Step 6: Remove an element from the array
    while (!validInput) {
        try {
            cout << "Enter an index to remove an element: ";
            cin >> removeIndex; // Get the index to remove
            cout << endl;

            arrayOps.removeElement(removeIndex); 

            // Display the result of the removal
            cout << "Removed value at index " << removeIndex << ".\n";

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    cout << "Updated Array:\n";
    arrayOps.printArray(); // Print the updated array

    return 0;
}
