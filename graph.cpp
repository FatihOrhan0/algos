#include <unordered_map>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <climits>
#include <queue>


using namespace std;

struct node {
    list<node *> edges;
    int dist = INT_MAX;
    int val;
    node() : val(0), dist(INT_MAX) {}
    node(int n) : val(n), dist(INT_MAX) { edges = list<node *>(); }
    bool colored = false;
};

vector<node *> createGraph(int n, double p) { 
    vector<node *> graph(n);
    for (int i = 0; i < n; i++) { 
        node * n = new node;
        graph[i] = n;
    }
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < i; j++) { 
            double r = (double) rand() / RAND_MAX;
            if (r <= p) { 
                graph[i]->edges.push_back(graph[j]);
                graph[j]->edges.push_back(graph[i]);
            }
        }
    }
    return graph;
}


//check if there is at least one component in the graph that has more than or as many as t
bool BFS(const vector<node *> & nodes, int t) {
    if (nodes.size() < t) return false;
    for (int i = 0; i < nodes.size(); i++) { 
        nodes[i]->dist = INT_MAX;
    }
    int totalSeen = 0, largest = 0, cur = 0;
    while (totalSeen < nodes.size()) { 
        cur = 0;
        int index = 0;
        while (index < nodes.size() && nodes[index]->dist != INT_MAX) index++;
        totalSeen++;
        nodes[index]->dist = 0;
        queue<node *> q;
        q.push(nodes[index]);
        cur++;
        while (!q.empty()) { 
            node * n = q.front();
            q.pop();
            for (auto edge : n->edges) { 
                if (edge->dist == INT_MAX) {
                    edge->dist = n->dist + 1;
                    q.push(edge);
                    cur++;
                    totalSeen++;
                }
            }
        }
        largest = max(largest, cur);
    }
    return largest >= t;
}

void DFS(const vector<node *> & graph, int n, vector<bool> & visited, const unordered_map<node *, int> & hash) { 
    visited[n] = true;
    cout << graph[n]->val << endl;
    for (node * edge : graph[n]->edges) { 
        if (!visited[hash.find(edge)->second]) {
            DFS(graph, hash.find(edge)->second, visited, hash);
        }
    }
    graph[n]->colored = true;
}

void DFSDriver(const vector<node *> & graph) {
    vector<bool> visited(graph.size(), false);
    unordered_map<node *, int> hash;
    for (int i = 0; i < graph.size(); i++) { 
        hash[graph[i]] = i;
    }
    DFS(graph, 2, visited, hash);
}



void destruct(vector<node *> & g) { 
    for (auto n : g) delete n;
}

int main() { 
    
    /* vector<int> res;
    for (double c = 0.2; c <= 3.1; c += 0.2) { 
        int num = 0;
        for (int i = 0; i < 500; i++) { 
            vector<node *> g = createGraph(40, c / 40);
            if (BFS(g, 30)) num++;
            destruct(g);
        }
        res.push_back(num);
    }
    for (int i = 0; i < res.size(); i++) { 
        cout << i + 1 << " " << res[i] << endl;
    } */

    node * one = new node(1);
    node * two = new node(2);
    node * three = new node(3);
    node * four = new node(4);
    node * five = new node(5);
    node * six = new node(6);
    node * seven = new node(7);
    node * eight = new node(8);
    one->edges.push_back(two);
    one->edges.push_back(three);
    two->edges.push_back(one);
    two->edges.push_back(three);
    two->edges.push_back(four);
    two->edges.push_back(five);
    three->edges.push_back(one);
    three->edges.push_back(two);
    three->edges.push_back(five);
    three->edges.push_back(seven);
    three->edges.push_back(eight);
    four->edges.push_back(two);
    four->edges.push_back(five);
    five->edges.push_back(two);
    five->edges.push_back(three);
    five->edges.push_back(four);
    five->edges.push_back(six);
    six->edges.push_back(five);
    seven->edges.push_back(three);
    seven->edges.push_back(eight);
    eight->edges.push_back(three);
    eight->edges.push_back(seven);

    vector<node *> nodes = {one, two, three, four, five, six, seven, eight};

    DFSDriver(nodes);

    destruct(nodes);

    return 0;
}