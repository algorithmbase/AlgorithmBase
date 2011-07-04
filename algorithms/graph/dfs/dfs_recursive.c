#include <stdio.h>
#include "dfs_recursive.h"

void dfs(int nodeCount, int edgeCount, char** matrix, char* visited, int currentNode) {
   int i = 0;

   // Has the current node been visited? Yes -- get out of here, because there is no
   // more work to be done.
   if (visited[currentNode]) {
   	return;
   }

   // Mark the node as visited. It is important to do it BEFORE the recursive calls to
   // dfs(), because otherwise we can get into an infinite loop (in this case, a stack
   // overflow).
   visited[currentNode] = 1;

   // Do your pre-processing here, for example printing the node, calculating it's 
   // pre-order index, etc.
   // The simplest example is:
   printf("Processing %d\n", currentNode);

   // Now iterate over all of the current node's neighbors.
   // No need to worry whether they're visited yet -- that will
   // be checked first-thing upon the recursive entry in dfs().
   for (i = 1; i <= nodeCount; i++) {
   	if (matrix[currentNode][i]) { // Make sure "currentNode" and "i" are connected.
   		dfs(nodeCount, edgeCount, matrix, visited, i);
   	}
   }

   // Do your post-processing here, for example printing the node, calculating it's 
   // post-order index, etc.
}
