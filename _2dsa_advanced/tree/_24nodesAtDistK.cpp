#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

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

// approach:
// 1. find the parent of all the nodes and store in the hash map, using lvl order trav
// 2. run a loop similar to bfs starting from the node given by user to print the nodes at dist k
// 3. create a map for taking care of visited nodes
// 4. strating from the givnen node and lvl as 1, goto its left rigth and parent nodes
// if they are not visited, then add them to queue, and mark them as visited
// 5. pop all the adjecents of the given node and continue the step 4 for all the nodes for next lvl
// do the same till lvl is not k
// when lvl==k, then come out of the loop and whatever nodes are in the queue are the nodes at dist k
// from the given node

// time: O(n)
// space: O(n)


void markParent(node *root,unordered_map<node *,node *>&mp,node *Node,int k)
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

vector<int> nodesAtDistK(node *root,node *Node,int k)
{
    vector<int>ans;
    if(root==NULL)
    return ans;
    unordered_map<node *,node *>mp;
    markParent(root,mp,Node,k);
    unordered_map<node *,bool>visited;
    queue<node *>q;
    q.push(Node);
    visited[Node]=true;
    // now, similar approach as bfs
    int currLvl=0;
    while(!q.empty())
    {
        int size=q.size();
        if(currLvl==k)
        break;
        currLvl++;
        // pop all the adjecents of the front node at once
        for(int i=0;i<size;i++)
        {
            node *curr=q.front();
            q.pop();
            if(curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(mp[curr] && !visited[mp[curr]])
            {
                q.push(mp[curr]);
                visited[mp[curr]]=true;
            }
        }
    }
    while(!q.empty())
    {
        ans.push_back(q.front()->key);
        q.pop();
    }
    return ans;
} 

int main()
{
    node *root=new node(20);
    root->left=new node(10);
    root->left->left=new node(34);
    root->left->right=new node(23);
    root->right=new node(13);
    root->right->left=new node(56);
    root->right->left->right=new node(16);
    root->right->right=new node(67);
    vector<int>ans=nodesAtDistK(root,root->right,2);
    cout<<"the nodes at distance k from the given node are ";
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}