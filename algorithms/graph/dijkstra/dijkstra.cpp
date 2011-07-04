// Source: http://www.algorithmbase.com
// Date: 2011/07/04
// Read: http://www.algorithmbase.com/229/dijkstra-s-algorithm/
#include <cfloat>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


//---------------------------------------------------------------------//
//                DIJKSTRA'S ALGORIRTHM IMPLEMENTATION                 //
//---------------------------------------------------------------------//

const int UNDEFINED = -1; // A utility constant used to indicate "not found".

/**
 * A class used to represent an edge in the graph.
 */
class Edge
{   
   public:
      int endPoint;
      double length;

      Edge(int aEndPoint, double aLength) { endPoint = aEndPoint; length = aLength; }
};

/**
 * Helper function: Finds the node closest to the source that has NOT
 * been visited yet.
 *
 * @return the index of the closest unvisited node (or -1 if all nodes have been visited)
 */
int find_closest_unvisited_node(int nodeCount, 
                                vector<double> &dist, 
                                vector<bool> &visited) 
{
   // Updated the current node to the closest unvisited neighbor.
   double currentBest = DBL_MAX;
   int currentNode = UNDEFINED;
   
   for (int i = 0; i < nodeCount; i++) 
   {
      if (!visited[i] && dist[i] < currentBest) 
      {
         currentBest = dist[i];
         currentNode = i;
      }
   }
   
   return currentNode;
}


/**
 * Helper function: Goes through all neighbors of a given node, and if the path
 * going through the node is better than the path to the neighbor, updates the path
 * to the neighbor to go through the given node.
 */
void update_neighbors_of_node(vector<Edge> &neighbors, 
                              vector<double> &dist, 
                              vector<int> &parent, 
                              int node) 
{   
   // Process all the neighbors of the current node
   for (unsigned i = 0; i < neighbors.size(); i++) 
   {
      int neighbor = neighbors[i].endPoint;
      double edgeLength = neighbors[i].length;
      
      // If the path to the current neighbor can be improved => improve it.
      if (dist[neighbor] > dist[node] + edgeLength) 
      {
         dist[neighbor] = dist[node] + edgeLength;
         parent[neighbor] = node;
      }
   }
}


/**
 * Helper function: Initializes the 3 helper arrays for Dijkstra's algorithm.
 */
void initialize_helper_vectors(vector<double> &dist, 
                               vector<bool> &visited, 
                               vector<int> &parent, 
                               int nodeCount) 
{
   // Initialize the helper vectors:
   // * dist[i] is infinity for every node.
   // * visited[i] is "false" for every node.
   // * parent[i] is UNDEFINED for every node.
   for (int i = 0; i <= nodeCount; i++) 
   {
      dist.push_back(DBL_MAX);
      visited.push_back(false);
      parent.push_back(UNDEFINED);
   }
}


/**
 * Helper function: Finds the node closest to the source that has NOT
 * been visited yet.
 *
 * @return the index of the closest unvisited node (or -1 if all nodes have been visited)
 */
void dijkstra(int nodeCount, 
              int edgeCount, 
              int from, 
              vector<vector<Edge> > &graph, 
              vector<double> &dist, 
              vector<int> &parent) 
{
   // A helper vector used to keep track of which nodes have already been procssed.
   vector<bool> visited;
   
   initialize_helper_vectors(dist, visited, parent, nodeCount);
   
   // Set the distance to the source node to 0, because it's at distance 0 from itself. :)
   dist[from] = 0;
   
   // Start the search from the source node.
   int currentNode = from;
   
   do 
   {
      
      // 1. Mark the current node as visited, so that we don't visit it again.
      visited[currentNode] = true;
      
      update_neighbors_of_node(graph[currentNode], dist, parent, currentNode);
      
      // 3. Updated the currentNode to the closest unvisited node in the graph.
      currentNode = find_closest_unvisited_node(nodeCount, dist, visited);
      
   } while (currentNode != UNDEFINED);
}
//---------------------------------------------------------------------//
//            DIJKSTRA'S ALGORIRTHM IMPLEMENTATION ENDS                //
//---------------------------------------------------------------------//

void read_input(vector<vector<Edge> > &graph, 
                int &nodeCount, 
                int &edgeCount, 
                int &from) 
{
   cin >> nodeCount >> edgeCount;
   
   for (int i = 0; i <= nodeCount; i++) 
   {
      graph.push_back(vector<Edge>());
   }
   
   for (int i = 0; i < edgeCount; i++) 
   {
      int edgeFrom, edgeTo;
      double edgeLength;
      
      cin >> edgeFrom >> edgeTo >> edgeLength;
      
      graph[edgeFrom].push_back(Edge(edgeTo, edgeLength));
      // NOTE: Remove this next line if your graph is directed.
      graph[edgeTo].push_back(Edge(edgeFrom, edgeLength));
   }
   
   cin >> from;
}


void reconstruct_path(vector<int> &parent, int destination, stack<int> &result) 
{
   while (destination != UNDEFINED) {
      result.push(destination);
      destination = parent[destination];
   }
}

void print_path(stack<int> reversedPath) 
{
   cout << "The path is: ";
   while (!reversedPath.empty()) 
   {
      cout << reversedPath.top() << " ";
      reversedPath.pop();
   }
   cout << endl;
}


void print_output(int nodeCount, vector<double> &dist, vector<int> &parent, int from) 
{
   for (int i = 1; i <= nodeCount; i++) 
   {
      if (dist[i] == DBL_MAX) 
      {
         cout << "There is no path from " << from << " to " << i << endl;
      } else 
      {
         cout << "The shortest path to " << i << " is " << dist[i] << endl;
         
         stack<int> reversedPath;
         
         reconstruct_path(parent, i, reversedPath);
         print_path(reversedPath);
      }
   }
}


int main() 
{
   int nodeCount;
   int edgeCount;
   int from;
   
   vector<vector<Edge> > graph;
   vector<double> dist;
   vector<int> parent;
   
   read_input(graph, nodeCount, edgeCount, from);
   
   dijkstra(nodeCount, edgeCount, from, graph, dist, parent);
   
   print_output(nodeCount, dist, parent, from);
   
   return 0;
}