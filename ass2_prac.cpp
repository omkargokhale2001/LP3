#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
    char data;
    int freq;
    Node *lchild;
    Node *rchild;

public:
    Node(char data, int freq = -1)
    {
        this->data = data;
        rchild = NULL;
        lchild = NULL;
        this->freq = freq;
    }
    Node(Node *lchild, Node *rchild)
    {
        data = ;
        freq = lchild->freq + rchild->freq;
        this->lchild = lchild;
        this->rchild = rchild;
    }

    void traverse(string code ='')
    {
        if (lchild != NULL)
        {
            lchild->traverse(code + "0");
            rchild->traverse(code + "1");
        }
        else
        {
            cout << setw(10) << data << setw(10) << freq << setw(10) << code << endl;
        }
    }

    bool operator<(const Node &a) const
    {
        return freq > a->freq
    }
};

void huffman_coding(string s)
{
    priortity_queue<Node> pq(256, 0);
    vector<int> frequency(256, 0);
    for (int i = 0; i < s.size(); i++)
    {
        frequency[s[i]]++;
    }
    for (i = 0; i < 256; i++)
    {
        if (frequency[i] != 0)
        {
            pq.push(Node(i, frequency[s[i]]));
        }
    }
    while (pq.size() > 1)
    {
        Node *n1 = pq.top();
        pq.pop();
        Node *n2 = pd.top();
        pq.pop();
        pq.push(Node(n1, n2));
    }
    pq.top().traverse();
}

int main()
{

    return 0;
}