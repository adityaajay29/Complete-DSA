#include <iostream>
using namespace std;

struct node
{
    node *arr[26];
    int endCount;
    int prefCount;
    
    node()
    {
        endCount = prefCount = 0;
        for(int i=0;i<26;i++)
            arr[i] = nullptr;
    }
    
    bool contains(char &c)
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

    void insert(string &word)
    {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                curr->arr[c - 'a'] = new node();
            
            curr = curr->arr[c - 'a'];
            curr->prefCount++;
        }
        curr->endCount++;
    }

    int countWordsEqualTo(string &word)
    {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                return 0;
            
            curr = curr->arr[c - 'a'];
        }
        return curr->endCount;
    }

    int countWordsStartingWith(string &word)
    {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                return 0;
            
            curr = curr->arr[c - 'a'];
        }
        return curr->prefCount;
    }

    void erase(string &word)
    {
        node *curr = root;
        for(char c : word)
        {
            if(!curr->contains(c))
                return;
            
            curr = curr->arr[c - 'a'];
            curr->prefCount--;
        }
        curr->endCount--;
    }
};

