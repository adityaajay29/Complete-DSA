#include <iostream>
using namespace std;

struct node
{
    node *arr[26];
    bool end;
    node()
    {
        end = false;
        for(int i=0;i<26;i++)
        {
            arr[i] = nullptr;
        }
    }

    bool contains(char c)
    {
        return arr[c - 'a'] != nullptr;
    }
};

class Trie
{
    private : node *root;

    public:
    Trie()
    {
        root = new node();
    }

    void insert(string &s)
    {
        node *curr = root;
        for(char c : s)
        {
            if(!curr->contains(c))
            curr->arr[c - 'a'] = new node();

            curr = curr->arr[c - 'a'];
        }
        curr->end = true;
    }

    bool search(string &s)
    {
        node *curr = root;
        for(char c : s)
        {
            if(!curr->contains(c))
            return false;

            curr = curr->arr[c - 'a'];
        }
        return curr->end;
    }

    bool isPrefix(string &s)
    {
        node *curr = root;
        for(char c : s)
        {
            if(!curr->contains(c))
            return false;

            curr = curr->arr[c - 'a'];
        }
        return true;
    }
};

int main()
{
    Trie t;

    string s = "apple";
    t.insert(s);
    string a = "app";
    cout<<t.search(s)<<endl<<t.isPrefix(a)<<endl;
    return 0;
}