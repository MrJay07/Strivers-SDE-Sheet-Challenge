#include<bits/stdc++.h>

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();          // get the number of rows 
    int n = matrix[0].size();       // get the number of columns
    bool firstRowZero = false;      // initialize flag for first row
    bool firstColZero = false;      // initialize flag for first column
    
    // check for zeros in the first row
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }
    // check for zeros in the first column
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    // traverse the matrix again and update first row and column as needed
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;   // update the first row flag
                matrix[i][0] = 0;   // update the first column flag
            }
        }
    }
    
    // traverse the matrix from the end and zero out rows and cols as needed
    for (int i = m - 1; i >= 1; i--) {         // start from the bottom row
        for (int j = n - 1; j >= 1; j--) {     // start from the rightmost column
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;   // if either the first row or first column is zero, set the element to zero
            }
        }
        // check if the first column needs to be zeroed
        if (firstColZero) {
            matrix[i][0] = 0;
        }
    }
    // check if the first row needs to be zeroed
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
}