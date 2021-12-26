#include <iostream>

class Node { 
    public:
    Node * next; 
    int val;
    Node(int i) : val(i) {}
    Node(int i, Node * n) : next(n), val(i) {}
};

unsigned int findSize(Node * root) { 
    if (!root) return 0;
    unsigned int total = 1; 
    while (root->next) { 
        total++; 
        root = root->next;
    }
    return total;
}

void print(Node * n) { 
    while (n) { 
        std::cout << n->val << " ";
        n = n->next;
    }
    std::cout << std::endl;
}

Node * reverse(Node * root, unsigned int size) { 
    if (size < 2) return root;
    if (size == 2) { 
        Node * temp = root->next;
        temp->next = root;
        root->next = NULL;
        return temp;
    }
    Node * temp = root;
    Node * p = root;
    Node * c = root->next;
    Node * n = root->next->next;
    for (int i = 0; i < size && n; i++) {
        c->next = p;
        p = c;
        c = n;
        n = n->next;
    }
    c->next = p;
    root->next = NULL;
    return c;
}

//a b c f e d g h 
//c b a f e d g h
//a b c d e f g h i 
//h g f e d c b a

//for given prev, store first, go k steps further 
//store the further(last) and further + 1(beyond)
// remove the first, and insert before beyond
//repeat above step k times.
//in the end update the prev's next to last

Node * reverseGroup(Node * root, int k) { 
    Node * start = root;
    Node * prev = NULL;
    Node * first = root;
    Node * last = first;
    Node * beyond = last;
    Node * laterPrev = first;
    Node * temp = first;
    while (true) {
        if (prev) { 
            first = prev->next;
            last = prev->next; 
        }
        for (int i = 0; i < k - 1; i++) { 
            last = last->next;
            if (!last) { 
                return start;
            }
        }  
        if (!last->next) { 
            Node * lastGroup = reverse(first, k);
            if (prev) {
                prev->next = lastGroup;
                return start;
            }
            else 
                return lastGroup;
        }
        else { 
            //5 4 3 6 7 8 9 10 11 12
            if (!beyond) return start;
            laterPrev = first;
            beyond = last->next;
            Node * laterBeyond = beyond;
            for (int i = 0; i < k; i++) { 
                temp = first->next;
                first->next = beyond;
                beyond = first;
                first = temp;
            }
            if (prev) {
                prev->next = last;
                prev = laterPrev;
            }
            else { 
                prev = laterPrev;
                start = last;
            }
            first = laterBeyond;
        }  
    }
}

int main() { 
    /*test cases here*/
}