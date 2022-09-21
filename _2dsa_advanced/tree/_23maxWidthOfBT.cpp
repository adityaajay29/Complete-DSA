#include <iostream>
#include <queue>
using namespace std;

// approach :
// Since we need to find the maximum weight of the Tree
// We will use level ordered traversal
// For each level index all the nodes strating from 0
// then count the number of nodes currently in the queue
// size of queue will be the max width of that level
// trick in implementing the indexing
// front item's id will be first
// rear item's id will be last
// so, no, of ele=last-first+1, since each id starts with 0

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

int maxWidth(node *root)
{
    if(root==NULL)
    return 0;
    queue<pair<node *,int> >q;
    q.push({root,0});
    int ans=0;
    while(!q.empty())
    {
        int first;
        int last;
        int n=q.size();
        // for every level, the 1st node will have the min id
        int minimum=q.front().second;
        // take out all the nodes of that level from the queue
        for(int i=0;i<n;i++)
        {
            node *curr=q.front().first;
            // use the min id to get the current id for that level starting from 0
            int curr_id=q.front().second-minimum;
            q.pop();
            // make 0th index ele of the queue as the first
            if(i==0)
            first=curr_id;
            // make the last indexed ele of the queue as the last
            if(i==n-1)
            last=curr_id;
            if(curr->left)
            {
                q.push({curr->left,2*curr_id+1});
            }
            if(curr->right)
            {
                q.push({curr->right,2*curr_id+2});
            }
        }
        // make the curr as last-1st + 1 
        // update the result
        ans=max(ans,last-first+1);
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
    root->right->right=new node(67);
    int ans=maxWidth(root);
    cout<<"the max width of the tree is "<<ans<<endl;
    return 0;
}