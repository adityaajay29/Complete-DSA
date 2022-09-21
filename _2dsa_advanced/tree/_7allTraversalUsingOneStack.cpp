#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// approach :
// create 3 diff arrays for 3 traversals
// create a stack with pair curr node, num
// node is the curr node, and num has following vals:
// put the root and num==1 in stack
// start the loop by popping the top
// if num==1, top will go to preorder and num will be ++ (2)
// put back the popped top with updated num val
// also, check if its left exists and push it to stack with num=1
// if num==2, top will go to inorder and num will be ++ (3)
// put back the popped top with updated num val
// also, check if its right exists and push it to stack with num=1
// if num==3, top will go to postorder and popped top will not be put back into stack

struct node
{
    int key;
    node *left;
    node *right;
    node (int x)
    {
        key=x;
        left=right=NULL;
    }
};

void allTraversalsInOne(node *root)
{
    vector<int>pre;
    vector<int>in;
    vector<int>po;
    stack<pair<node *,int> >s;
    s.push({root,1});
    while(!s.empty())
    {
        node *curr=s.top().first;
        int num=s.top().second;
        if(num==1)
        {
            pre.push_back(curr->key);
            // update the top.second, not num becuase the loop will then enter else if also
            s.top().second++;
            if(curr->left)
            {
                s.push({curr->left,1});
            }
        }
        else if(num==2)
        {
            in.push_back(curr->key);
            // update the top.second, not num becuase the loop will then enter else if also
            s.top().second++;
            if(curr->right)
            {
                s.push({curr->right,1});
            }
        }
        else 
        {
            po.push_back(curr->key);
            s.pop();
        }
    }
    cout<<"preorder : ";
    for(auto x:pre)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"inorder : ";
    for(auto x:in)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"postorder : ";
    for(auto x:po)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

// void allTraversalsInOne(node *root)
// {
//     vector<int>pre;
//     vector<int>in;
//     vector<int>po;
//     stack<pair<node *,int> >s;
//     s.push({root,1});
//     while(!s.empty())
//     {
//         node *curr=s.top().first;
//         int num=s.top().second;
//         s.pop();
//         if(num==1)
//         {
//             pre.push_back(curr->key);
//             num++;
//             s.push({curr,num});
//             if(curr->left)
//             {
//                 s.push({curr->left,1});
//             }
//         }
//         else if(num==2)
//         {
//             in.push_back(curr->key);
//             num++;
//             s.push({curr,num});
//             if(curr->right)
//             {
//                 s.push({curr->right,1});
//             }
//         }
//         else 
//         {
//             po.push_back(curr->key);
//         }
//     }
//     cout<<"preorder : ";
//     for(auto x:pre)
//     {
//         cout<<x<<" ";
//     }
//     cout<<endl;
//     cout<<"inorder : ";
//     for(auto x:in)
//     {
//         cout<<x<<" ";
//     }
//     cout<<endl;
//     cout<<"postorder : ";
//     for(auto x:po)
//     {
//         cout<<x<<" ";
//     }
//     cout<<endl;
// }

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(3);
    root->left->right=new node(4);
    root->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    allTraversalsInOne(root);
    return 0;
}