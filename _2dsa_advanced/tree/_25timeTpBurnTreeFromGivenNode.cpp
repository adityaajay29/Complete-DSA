#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// approach:
// similar to find nodes at distance k
// whenever going to the next lvl, check if it is not already visited, then only burn
// to keep track of whether to increase the time, use a bool flag, initially reset
// set the flag when burning either left or right or parent or all
// if the flag is set, meaning some node has burnt, increase the time
// else, no change in time 

// time:O(n)
// space:O(n)

struct node
{
    int key;
    node *left;
    node *right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

void markParent(node *root,node *Node,unordered_map<node *,node *>&mp)
{
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        if(curr->left)
        {
            q.push(curr->left);
            mp[curr->left]=curr;
        }
        if(curr->right)
        {
            q.push(curr->right);
            mp[curr->right]=curr;
        }
    }
}

int timeTakenToBurnTree(node *root,node *Node)
{
    if(root==NULL)
    return 0;
    unordered_map<node *,node *>mp;
    markParent(root,Node,mp);
    unordered_map<node *,bool>visited;
    queue<node *>q;
    q.push(Node);
    visited[Node]=true;
    int time=0;
    while(!q.empty())
    {
        int size=q.size();
        bool flag=false;
        for(int i=0;i<size;i++)
        {
            node *curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left])
            {
                flag=true;
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right && !visited[curr->right])
            {
                flag=true;
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(mp[curr] && !visited[mp[curr]])
            {
                flag=true;
                q.push(mp[curr]);
                visited[mp[curr]]=true;
            }
        }
        if(flag)
        time++;
    }
    return time;
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->left->right=new node(7);
    root->right=new node(3);
    root->right->left=new node(5);
    root->right->right=new node(6);
    int time=timeTakenToBurnTree(root,root->left);
    cout<<"the time taken to burn the tree completely from given node is "<<time<<endl;
    return 0;
}