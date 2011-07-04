// Source: http://www.algorithmbase.com
// Date: 2011/07/04
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void floyd(int nodeCount, int** matrix) {
	for (int k = 1; k <= nodeCount; k++) { // Check every intermediate node
		for (int i = 1; i <= nodeCount; i++) { // Check every start node
			for (int j = 1; j <= nodeCount; j++) { // Check every end node
				// If the path from I to J can be optimized by going through K - go head and do it.
				if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}
}

int main() {
	int nodeCount;
	int edgeCount;
	int **m;
	
	cin >> nodeCount >> edgeCount;
	
	m = new int*[nodeCount + 1];
	
	for (int i = 0; i <= nodeCount; i++) {
		m[i] = new int[nodeCount + 1];
	}
	
	for (int i = 1; i <= nodeCount; i++) {
		for (int j = 1; j <= nodeCount; j++) {
			m[i][j] = INT_MAX;
		}
	}
	
	for (int i = 0; i < edgeCount; i++) {
		int a, b, price;
		
		cin >> a >> b >> price;
		
		m[a][b] = price;
		m[b][a] = price;
	}
	
	floyd(nodeCount, m);
	
	int questions;
	
	cin >> questions;
	
	for (int i = 0; i < questions; i++) {
		int a, b;
		cin >> a >> b;
		cout << m[a][b] << endl;
	}
	return 0;
}