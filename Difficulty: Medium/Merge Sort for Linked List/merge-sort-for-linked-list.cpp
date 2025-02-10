//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    // Function to find the middle node
    Node* findmid(Node* head) {
        if (!head || !head->next) return head;  // Ensure there's more than one node

        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {  // Ensure fast->next->next is not NULL
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;  // Return the middle node
    }

    // Function to merge two sorted linked lists
    Node* merge(Node* le, Node* ri) {
        if (!le) return ri;
        if (!ri) return le;

        Node* head = nullptr;
        Node* tail = nullptr;

        // Initialize head and tail
        if (le->data <= ri->data) {
            head = tail = le;
            le = le->next;
        } else {
            head = tail = ri;
            ri = ri->next;
        }

        // Merge the two sorted lists
        while (le && ri) {
            if (le->data <= ri->data) {
                tail->next = le;
                le = le->next;
            } else {
                tail->next = ri;
                ri = ri->next;
            }
            tail = tail->next;
        }

        // Append the remaining elements
        if (le) tail->next = le;
        if (ri) tail->next = ri;

        return head;
    }

    // Merge Sort function for linked list
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;  // Base case: empty or single node

        Node* mid = findmid(head);
        Node* right = mid->next;
        mid->next = nullptr;  // Split the list into two halves

        Node* leftSorted = mergeSort(head);
        Node* rightSorted = mergeSort(right);

        return merge(leftSorted, rightSorted);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends