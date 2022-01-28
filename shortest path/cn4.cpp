// C++ implementation to find the
// shortest path in a directed
// graph from source vertex to
// the destination vertex

#include <bits/stdc++.h>
#define infi 1000000000
using namespace std;

// Class of the node
class Node {
public:
	int vertexNumber;

	// Adjacency list that shows the
	// vertexNumber of child vertex
	// and the weight of the edge
	vector<pair<int, int> > children;
	Node(int vertexNumber)
	{
		this->vertexNumber = vertexNumber;
	}

	// Function to add the child for
	// the given node
	void add_child(int vNumber, int length)
	{
		pair<int, int> p;
		p.first = vNumber;
		p.second = length;
		children.push_back(p);
	}
};

// Function to find the distance of
// the node from the given source
// vertex to the destination vertex
vector<int> dijkstraDist(
	vector<Node*> g,
	int s, vector<int>& path)
{
	// Stores distance of each
	// vertex from source vertex
	vector<int> dist(g.size());

	// Boolean array that shows
	// whether the vertex 'i'
	// is visited or not
	bool visited[g.size()];
	for (int i = 0; i < g.size(); i++) {
		visited[i] = false;
		path[i] = -1;
		dist[i] = infi;
	}
	dist[s] = 0;
	path[s] = -1;
	int current = s;

	// Set of vertices that has
	// a parent (one or more)
	// marked as visited
	unordered_set<int> sett;
	while (true) {

		// Mark current as visited
		visited[current] = true;
		for (int i = 0;
			i < g[current]->children.size();
			i++) {
			int v = g[current]->children[i].first;
			if (visited[v])
				continue;

			// Inserting into the
			// visited vertex
			sett.insert(v);
			int alt
				= dist[current]
				+ g[current]->children[i].second;

			// Condition to check the distance
			// is correct and update it
			// if it is minimum from the previous
			// computed distance
			if (alt < dist[v]) {
				dist[v] = alt;
				path[v] = current;
			}
		}
		sett.erase(current);
		if (sett.empty())
			break;

		// The new current
		int minDist = infi;
		int index = 0;

		// Loop to update the distance
		// of the vertices of the graph
		for (int a: sett) {
			if (dist[a] < minDist) {
				minDist = dist[a];
				index = a;
			}
		}
		current = index;
	}
	return dist;
}

// Function to print the path
// from the source vertex to
// the destination vertex
void printPath(vector<int> path,
			int i, int s)
{
	if (i != s) {

		// Condition to check if
		// there is no path between
		// the Nodes
		if (path[i] == -1) {
			cout << "Path not found!!";
			return;
		}
		printPath(path, path[i], s);
		cout << path[i] << " ";
	}
}

// Driver Code
int main()
{
	vector<Node*> v;
	int n = 51, s = 0, e = 52;

	// Loop to create the nodes
	for (int i = 0; i < n; i++) {
		Node* a = new Node(i);
		v.push_back(a);
	}

	// Creating directed
	// weighted edges
	v[0]->add_child(1, 1);
	v[0]->add_child(2, 4);
	v[1]->add_child(2, 2);
	v[1]->add_child(3, 6);
	v[2]->add_child(3, 3);
    v[2]->add_child(3, 4);
    v[3]->add_child(4, 5);
    v[3]->add_child(4, 3);
    v[4]->add_child(5, 10);
    v[4]->add_child(5, 1);
    v[5]->add_child(6, 4);
    v[5]->add_child(6, 12);
    v[6]->add_child(7, 13);
    v[6]->add_child(7, 7);
    v[7]->add_child(8, 3);
    v[7]->add_child(8, 2);
    v[8]->add_child(9, 8);
    v[8]->add_child(9, 9);
    v[9]->add_child(10, 4);
    v[9]->add_child(10, 3);
    v[10]->add_child(11, 2);
    v[10]->add_child(11, 1);
    v[11]->add_child(12, 9);
    v[11]->add_child(12, 6);
    v[12]->add_child(13, 4);
    v[12]->add_child(13, 7);
    v[13]->add_child(14, 3);
    v[13]->add_child(14, 4);
    v[14]->add_child(15, 3);
    v[14]->add_child(15, 5);
    v[15]->add_child(16, 10);
    v[15]->add_child(16, 5);
    v[16]->add_child(17, 11);
    v[16]->add_child(17, 7);
    v[17]->add_child(18, 8);
    v[17]->add_child(18, 2);
    v[18]->add_child(19, 1);
    v[18]->add_child(19, 9);
    v[19]->add_child(20, 6);
    v[19]->add_child(20, 4);
    v[20]->add_child(21, 7);
    v[20]->add_child(21, 7);
    v[21]->add_child(22, 9);
    v[21]->add_child(22, 6);
    v[22]->add_child(23, 4);
    v[22]->add_child(23, 7);
    v[23]->add_child(24, 3);
    v[23]->add_child(24, 4);
    v[24]->add_child(25, 3);
    v[24]->add_child(25, 5);
    v[25]->add_child(26, 10);
    v[25]->add_child(26, 5);
    v[26]->add_child(27, 11);
    v[26]->add_child(27, 7);
    v[27]->add_child(28, 8);
    v[27]->add_child(28, 2);
    v[28]->add_child(29, 1);
    v[28]->add_child(29, 9);
    v[29]->add_child(30, 6);
    v[29]->add_child(30, 4);
    v[30]->add_child(31, 7);
    v[30]->add_child(31, 7);
    v[31]->add_child(32, 9);
    v[31]->add_child(32, 6);
    v[32]->add_child(33, 4);
    v[32]->add_child(33, 7);
    v[33]->add_child(34, 3);
    v[33]->add_child(34, 4);
    v[34]->add_child(35, 3);
    v[34]->add_child(35, 5);
    v[35]->add_child(36, 10);
    v[35]->add_child(36, 5);
    v[36]->add_child(37, 11);
    v[36]->add_child(37, 7);
    v[37]->add_child(38, 8);
    v[37]->add_child(38, 2);
    v[38]->add_child(39, 1);
    v[38]->add_child(39, 9);
    v[39]->add_child(40, 6);
    v[39]->add_child(40, 4);
    v[40]->add_child(41, 7);
    v[40]->add_child(41, 7);
    v[41]->add_child(42, 9);
    v[41]->add_child(42, 6);
    v[42]->add_child(43, 4);
    v[42]->add_child(43, 7);
    v[43]->add_child(44, 3);
    v[43]->add_child(44, 4);
    v[44]->add_child(45, 3);
    v[44]->add_child(45, 5);
    v[45]->add_child(46, 10);
    v[45]->add_child(46, 5);
    v[46]->add_child(47, 11);
    v[46]->add_child(47, 7);
    v[47]->add_child(48, 8);
    v[47]->add_child(48, 2);
    v[48]->add_child(49, 1);
    v[48]->add_child(49, 9);
    v[49]->add_child(50, 6);
    v[49]->add_child(50, 4);
    
    


	vector<int> path(v.size());
	vector<int> dist
		= dijkstraDist(v, s, path);

	// Loop to print the distance of
	// every node from source Node
	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] == infi) {
			cout << i << " and " << s
				<< " are not connected"
				<< endl;
			continue;
		}
		cout << "Distance of " << i
			<< "th Node from source Node "
			<< s << " is: "
			<< dist[i] << endl;
	}
	return 0;
}
