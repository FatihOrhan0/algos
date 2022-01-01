#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;


//representation of the Node class: The class has templated value T and
//arbitrary number of elements stored in a vector. 
template <class T> 
class Node { 
public: 
    Node(double d) : val(d) {}
    std::vector<Node *> ptrs;
    T val;
};

template <class T> 
bool isLeaf(Node<T> n) { 
    bool b = true;
    for (unsigned int i = 0; i < n.ptrs.size(); i++) { 
        if (n.ptrs[i]) { b = false; }
    }
    return b;
}

//a generic iterative function that returns the height of a tree with templated 
//nodes and arbitrary number of children. Takes the root node as argument
template <class T>
unsigned int height(Node<T> * p) { 
    if (!p) { return 0; } 
    unsigned int max = 1;
    std::list<std::pair<Node<T> *, unsigned int> > nodes;
    nodes.push_back(std::make_pair(p, 1));
    auto itr = nodes.begin();
    while (nodes.size() > 0) { 
        itr = nodes.begin(); 
        for (unsigned int i = 0; i < itr->first->ptrs.size(); i++) { 
            if (itr->first->ptrs[i]) { 
                nodes.push_back(std::make_pair(itr->first->ptrs[i], itr->second + 1));
                if (itr->second + 1 > max) max = itr->second + 1;
            }
        }
        nodes.erase(itr);
    }
    return max;
}

//since there is no parent pointer in the node representation, best option for
//deleting a tree with root given is storing each node in a list and delete 
//all elements of the list at the very end.
//needless to note, this function is for dynamically allocated trees only.
template<class T>
void deleteTree(Node<T> *& root) { 
    std::list<Node<T> *> nodes; 
    nodes.push_back(root);
    auto itr = nodes.begin(); 
    while (itr != nodes.end()) { 
        for (unsigned int i = 0; i < (*itr)->ptrs.size(); i++) { 
            if ((*itr)->ptrs[i])
                nodes.push_back((*itr)->ptrs[i]);
        }
        itr++;
    }
    for (auto it = nodes.begin(); it != nodes.end(); it++) { 
        std::cout << (*it)->val << ' ';
    }
    for (auto itz = nodes.rbegin(); itz != nodes.rend(); itz++) { 
        (*itz)->ptrs.clear();
        delete *itz;
        (*itz) = NULL;
    }
    root = NULL;
    nodes.clear();
}


//an iterative function to print the nodes of the tree post-order.
//Takes the root as its only argument.
template <class T>
void print(Node<T> * root) { 
    std::stack<std::pair<Node<T>*, int> > printables;
    printables.push(std::make_pair(root, 0));   
    while (!printables.empty()) { 
        if (isLeaf(*printables.top().first)) {
            std::cout << printables.top().first->val << " ";
            printables.pop();
        }
        if (printables.top().second == (int) printables.top().first->ptrs.size()) { 
            std::cout << printables.top().first->val << " ";
            printables.pop();
        }
        else { 
            bool added = false;
            for (unsigned int i = printables.top().second;
                 i < printables.top().first->ptrs.size(); i++) { 
                if (printables.top().first->ptrs[i]) { 
                    printables.top().second = i + 1;
                    printables.push(std::make_pair(printables.top().first->ptrs[i], 0));
                    added = true;
                    break;
                }
            }
            if (!added) { 
                std::cout << printables.top().first->val << " ";
                printables.pop();
            }
        }
    }
} 

int main() { 
    Node<int> a(3);
    Node<int> b(8);
    Node<int> c(10);
    Node<int> d(5);
    Node<int> e(7);
    Node<int> f(1);
    Node<int> g(6);
    Node<int> h(9);
    Node<int> i(4);

    a.ptrs.push_back(&b);
    a.ptrs.push_back(&c);
    b.ptrs.push_back(&d);
    b.ptrs.push_back(&e);
    c.ptrs.push_back(&f);
    c.ptrs.push_back(&g);
    d.ptrs.push_back(&h);
    d.ptrs.push_back(&i);
    std::cout << height<int>(&a) << std::endl;

    

    
}