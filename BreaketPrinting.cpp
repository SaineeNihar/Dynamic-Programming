// A space optimized C++ program to print optimal 
// parenthesization in matrix chain multiplication. 
#include<bits/stdc++.h> 
using namespace std; 
// Function for printing the optimal 
// parenthesization of a matrix chain product 
void printParenthesis(int i, int j, int n, int *bracket, char &name) 
{ 
	// If only one matrix left in current segment 
	if (i == j) 
	{ 
		cout << name++; 
		return; 
	} 
	cout << "("; 
	// Recursively put brackets around subexpression 
	// from i to bracket[j][i]. 
	// Note that "*((bracket+j*n)+i)" is similar to 
	// bracket[j][i] 
	printParenthesis(i, *((bracket+j*n)+i), n, 
					bracket, name); 
	// Recursively put brackets around subexpression 
	// from bracket[j][i] + 1 to i. 
	printParenthesis(*((bracket+j*n)+i) + 1, j, n, bracket, name); 
	cout << ")"; 
} 
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n 
// Please refer below article for details of this 
// function 
void matrixChainOrder(int p[], int n) 
{ 
	/* 
    For simplicity of the program, one extra 
	row and one extra column are allocated in 
	m[][]. 0th row and 0th column of m[][] 
	are not used 
    */
	int m[n][n]; 
	/* m[i,j] = Minimum number of scalar multiplications needed to compute 
    the matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is p[i-1] x p[i] */
	
    // cost is zero when multiplying one matrix. 
	for (int i=1; i<n; i++) 
		m[i][i] = 0; 
	// L is chain length. 
	for (int L=2; L<n; L++) 
	{ 
		for (int i=1; i<n-L+1; i++) 
		{ 
			int j = i+L-1; 
			m[i][j] = INT_MAX; 
			for (int k=i; k<=j-1; k++) 
			{ 
				// q = cost/scalar multiplications 
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
				if (q < m[i][j]) 
				{ 
					m[i][j] = q; 
					// Each entry m[j,ji=k shows where to split 
                    //the product arr i,i+1....j for the minimum cost. 
					m[j][i] = k; 
				} 
			} 
		} 
	} 
	// The first matrix is printed as 'A', next as 'B', and so on 
	char name = 'A'; 
	cout << "Optimal Parenthesization is: "; 
	printParenthesis(1, n-1, n, (int *)m, name); 
	cout << "\nOptimal Cost is : " << m[1][n-1]; 
} 
// Driver code 
int main() 
{ 
	int arr[] = {40, 20, 30, 10, 30}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	matrixChainOrder(arr, n); 
	return 0; 
} 