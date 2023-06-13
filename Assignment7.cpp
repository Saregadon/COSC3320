#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman tree node
struct Node {
    char letter;
    unsigned count;
    Node* left, * right;

    Node(char letter, unsigned count) : letter(letter), count(count), left(nullptr), right(nullptr) {}
};

// Comparison operator for priority queue
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->count > r->count;
    }
};

// Build Huffman tree and generate codes
unordered_map<char, string> buildHuffmanTree(string text) {
    // Count the frequency of each character
    unordered_map<char, unsigned> frequencies;
    for (char c : text) {
        frequencies[c]++;
    }

    // Create a priority queue (min-heap) to store the nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : frequencies) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->count + right->count);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Generate Huffman codes
    unordered_map<char, string> codes;
    if (!pq.empty()) {
        Node* root = pq.top();
        string currentCode = "";
        // Traverse the Huffman tree and assign codes
        queue<pair<Node*, string>> nodeQueue;
        nodeQueue.push(make_pair(root, currentCode));

        while (!nodeQueue.empty()) {
            Node* node = nodeQueue.front().first;
            currentCode = nodeQueue.front().second;
            nodeQueue.pop();

            if (!node->left && !node->right) {
                codes[node->letter] = currentCode;
            }

            if (node->left) {
                nodeQueue.push(make_pair(node->left, currentCode + "0"));
            }

            if (node->right) {
                nodeQueue.push(make_pair(node->right, currentCode + "1"));
            }
        }
    }

    return codes;
}

int main() {
    string text = "abcde";
    
    unordered_map<char, string> codes = buildHuffmanTree(text);
    // Display the generated Huffman codes
    cout << "Huffman Codes:" << endl;
    for (auto pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}

/*
The provided code implements the Huffman coding algorithm to build a Huffman tree and generate 
Huffman codes for characters in a given text. The code defines a Node struct representing a node 
in the Huffman tree, and a compare struct as the comparison operator for the priority queue used 
to build the tree. The buildHuffmanTree function takes a string as input, counts the frequency 
of each character in the text, creates a priority queue of nodes based on the frequencies, builds 
the Huffman tree using the priority queue, and generates Huffman codes for each character. The 
generated codes are stored in an unordered map. Finally, the generated Huffman codes are displayed 
on the console.

Time Complexity:

Counting the frequency of each character in the input text takes O(n) time, where n is the 
length of the text.
Building the Huffman tree involves iterating over the frequencies and performing operations on 
the priority queue. Each iteration takes O(log n) time, where n is the number of distinct characters 
in the text. Therefore, building the Huffman tree has a time complexity of O(n log n) in the worst case.
Generating Huffman codes involves traversing the Huffman tree, which has a total of n nodes (n is 
the number of distinct characters). The traversal operation takes O(n) time, as each node is visited 
exactly once. Thus, generating the Huffman codes has a time complexity of O(n).
Overall, the time complexity of the buildHuffmanTree function is O(n log n).

Space Complexity:

The space required for storing the characters and their frequencies in the unordered map is proportional 
to the number of distinct characters in the text, which can be at most O(n), where n is the length of the text.
The priority queue stores the nodes of the Huffman tree. The maximum number of nodes in the tree is equal 
to the number of distinct characters, which can be at most O(n).
The generated Huffman codes are stored in an unordered map, which requires space proportional to the number 
of distinct characters, i.e., O(n).
In addition to the input text, the space complexity is dominated by the Huffman tree, which is proportional 
to the number of distinct characters, i.e., O(n).
Overall, the space complexity of the code is O(n).

*/