
#include<iostream>

using namespace std;
int max(int a, int b, int c);
int main() {

	string A = "ABCCA";
	string B = "ABBC";
	int match = 2; // match
	int mismatch = -1; // mismatch
	int gap = -2; // gap
	int i, j;

	// calculate the string size
	int m = A.length();
	int n = B.length();

	//construct a table
	int** M = new int* [m];
	for (i = 0; i <= m; ++i)
		M[i] = new int[n];

	//insert first row and column with gap
	for (i = 0; i <= n; i++) {
		M[i][0] = i * gap;
	}
	for (j = 0; j <= m; j++) {
		M[0][j] = j * gap;
	}

	//calculate the whole matrix
	for (i = 1; i <= n; i++) {
		for ( j = 1; j <= m; j++) {
			int Try1 = 0;
			int Try2 = 0;
			int Try3 = 0;
			if (B[i - 1] == A[j - 1]) {
				Try1 = M[i - 1][j - 1] + match;
				Try2 = M[i - 1][j] + gap;
				Try3 = M[i][j - 1] + gap;
				M[i][j] = max(Try1, Try2, Try3);
			}
			else {
				Try1 = M[i - 1][j - 1] + mismatch;
				Try2 = M[i - 1][j] + gap;
				Try3 = M[i][j - 1] + gap;
				M[i][j] = max(Try1, Try2, Try3);
			}
		}
	}
	//PRINT
	cout << "        ";
	for ( i = 0; i <= m; i++) {
		cout << A[i] << "   ";
	}
	cout << "\n  ";

	for ( i = 0; i <= n; i++) {
		if (i > 0) {
			cout << B[i - 1] << " ";
		}

		for ( j = 0; j <= m; j++) {
			cout.width(3);
			cout << M[i][j] << "  ";
		}
		cout << endl;
	}
	//int maxx = m[0][0];
	//for (int i = 1; i <= n; i++) {
	//	for (j = 1; j <= m; j++)
	//	{

	//		if (m[i][j] > maxx) {
	//			maxx = m[i][j];
	//		}
	//	}


	//}

	cout << "the score is : " << M[n][m] << endl;
	string seq1 = "";
	string seq2 = "";
	int i1 = n;
	int j1 = m;

	while (i1 > 0 && j1 > 0) {
		if (A[j1 - 1] == B[i1 - 1]) {
			seq1 += A[j1 - 1];
			seq2 += B[i1 - 1];
			i1--;
			j1--;
		}
		else {
			int maxs = max(M[i1 - 1][j1 - 1], M[i1 - 1][j1], M[i1][j1 - 1]);
			if (maxs == M[i1 - 1][j1 - 1]) {
				seq1 += A[j1 - 1];
				seq2 += B[i1 - 1];
				i1--;
				j1--;

			}
			else if (maxs == M[i1 - 1][j1]) {
				seq1 += "_";
				seq2 += B[i1 - 1];
				i1--;

			}
			else if (maxs == M[i1][j1 - 1]) {
				seq1 += A[j1 - 1];
				seq2 += "_";
				j1--;

			}
		}
	}
	cout << "seq1= ";
	for ( i = n; i >= 0; i--) {
		cout << seq1[i] << " ";
	}
	cout << endl;
	cout << "seq2= ";
	for ( j = n; j >= 0; j--) {
		cout << seq2[j] << " ";
	}
	cout << endl;


}






// function for maximum value
int max(int a, int b, int c) {
	if (a > b && a > c) {
		return a;
	}
	else if (b > a && b > c) {
		return b;
	}
	else {
		return c;
	}

}

















