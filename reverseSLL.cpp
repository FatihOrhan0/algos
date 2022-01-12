//a file that has functions for finding the size of, printing, reversing,
//and reversing in groups of sll

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
    Node * p = root;
    Node * c = root->next;
    Node * n = root->next->next;
    for (unsigned int i = 0; i < size && n; i++) {
        c->next = p;
        p = c;
        c = n;
        n = n->next;
    }
    c->next = p;
    root->next = NULL;
    return c;
}


//solution to https://leetcode.com/problems/swap-nodes-in-pairs/
//a very straightforward recursive algorithm.
Node* swapPairs(Node* head) {
    if (!head || !head->next) return head;
    if (!head->next->next) { 
        Node * temp = head->next;
        temp->next = head;
        head->next = NULL;
        return temp;
    }
    else { 
        Node * temp = swapPairs(head->next->next);
        Node * tempNext = head->next;
        head->next = temp;
        tempNext->next = head;
        return tempNext;
    }
}

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
    Node * a = new Node(1);
    a->next = new Node(2);
    a->next->next = new Node(3);
    a->next->next->next = new Node(4);
    a->next->next->next->next = new Node(5);
    // a->next->next->next = new Node(6);

    a = swapPairs(a);
    print(a);
}