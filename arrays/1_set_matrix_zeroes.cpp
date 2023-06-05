#include <bits/stdc++.h>

using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	// Brute - make a new matrix with the same elements and everytime you encounter 0 make changes in matrix
	// TC - O(N*M*(N+M))
	// SC - O(N*M)
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>> temp(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = matrix[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				for (int k = 0; k < n; k++) {
					matrix[k][j] = 0;
				}
				for (int k = 0; k < m; k++) {
					matrix[i][k] = 0;
				}
			}
		}
	}
}

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	// Brute - make a new matrix with the same elements and everytime you encounter 0 make changes in matrix
	// TC - O((N*M)*(N+M)) + O(N*M)
	// SC - O(1)
	int n = matrix.size(), m = matrix[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				for (int k = 0; k < n; k++) {
					if (matrix[k][j] != -1)
						matrix[k][j] = -1;
				}
				for (int k = 0; k < m; k++) {
					if (matrix[i][k] != -1)
						matrix[i][k] = -1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == -1) {
				matrix[i][j] = 0;
			}
		}
	}
}

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	// Better - traverse the matrix and maintain a 1d array of row and col size, if we encounter zero make row and col index as true which marks that the element is 0
	// now traverse the matrix again and check if either row or col index is set make the element 0

	// TC - O(2(n*m))
	// SC - O(n+m)

	int n = matrix.size(), m = matrix[0].size();

	vector<int> row(n, 0), col(m, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (row[i] or col[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	// Traverse the matrix and use the first column and row as the marking array, matrix[0][0] will take 2 places so use another variable


	// TC - O(2(n*m))
	// SC - O(1)

	int n = matrix.size(), m = matrix[0].size(), col = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				if (j != 0)
					matrix[0][j] = 0;
				else
					col = 0;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (matrix[i][0] == 0 or matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
	if (matrix[0][0] == 0) {
		for (int i = 0; i < m; i++) {
			matrix[0][i] = 0;
		}
	}
	if (col == 0) {
		for (int j = 0; j < n; j++) {
			matrix[j][0] = 0;
		}
	}
}