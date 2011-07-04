#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfs_recursive.h"

char** matrix;
int nodeCount = 0;
int edgeCount = 0;
char* visited;

int main() {
	int i = 0;
	int from = 0;
	int to = 0;
	
	scanf("%d%d", &nodeCount, &edgeCount);
	
	visited = (char *)malloc((nodeCount + 1) * sizeof(char));
	matrix = (char **)malloc((nodeCount + 1) * sizeof(char *));
	
	for (i = 0; i <= nodeCount; i++) {
		visited[i] = 0;
		matrix[i] = (char *)malloc((nodeCount + 1) * sizeof(char));
		memset(matrix[i], 0, (nodeCount + 1) * sizeof(char));
	}
	
	for (i = 0; i < edgeCount; i++) {
		scanf("%d%d", &from, &to);
		matrix[from][to] = matrix[to][from] = 1;
	}
	
	dfs(nodeCount, edgeCount, matrix, visited, 1);
	return 0;
}