//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author [Sebastian Quirarte]
 * @date [11/12/25 last edited]
 * @version 1.0
 */

#include "FileUtils.h"
#include "Exceptions.h"     // Include for student's custom exceptions
#include <iostream>         // For cout, cerr, cin
#include <string>           // For string
#include <fstream>          // For ifstream

using namespace std;

/**
 * @brief Attempts to open a file, handling failures and retries.
 * * This function contains the logic that the student must
 * convert to use try...catch with FileOpenException.
 *
 * @param file The ifstream object to be opened (passed by reference).
 * @param initialFilename The first filename to try.
 */
void openFileForReading(ifstream& file, string initialFilename) {
    // STUDENT TODO: Replace the following 'if' block with a
    // try...catch block that throws and catches a FileOpenException.
    try {
        file.open(initialFilename);
        if (!file.is_open()) {
            throw FileOpenException("Error: File could not be opened: " + initialFilename);
        }
        cout << "File opened successfully: " << initialFilename << endl;
    }
    catch (const FileOpenException& e) {
        cerr << e.what() << endl;
        string alternativeFilename;
        cout << "Enter alternative filename: \n" ;
        cin >> alternativeFilename;

        file.open(alternativeFilename);
        if (!file.is_open()) {
            cerr << "Error: Failed to open alternative file. Exiting." << endl;;
            exit(1);

        }
        cout << "Alternative file opened successfully: " << alternativeFilename << endl;
    }
}

