#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

vector<ListNode *> levelnodes;

void insert_node(TreeNode *node, int n)
{
    int current_node_val = node->val;
    if (n <= current_node_val)
    {
        if (node->left == NULL)
        {
            TreeNode *new_node;
            new_node = new TreeNode(n);
            node->left = new_node;
        }
        else
        {
            insert_node(node->left, n);
        }
    }
    else
    {
        if (node->right == NULL)
        {
            TreeNode *new_node;
            new_node = new TreeNode(n);
            node->right = new_node;
        }
        else
        {
            insert_node(node->right, n);
        }
    }
}

void inorder_traversal(TreeNode *node)
{
    if (node != NULL)
    {
        inorder_traversal(node->left);
        cout << node->val << " ";
        inorder_traversal(node->right);
    }
}

void preorder_traversal(TreeNode *node)
{
    if (node != NULL)
    {
        cout << node->val << " ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}

void postorder_traversal(TreeNode *node)
{
    if (node != NULL)
    {
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        cout << node->val << " ";
    }
}

bool find_node(TreeNode *node, int n)
{
    if (node->val == n)
        return true;
    else if (n < node->val)
    {
        if (node->left != NULL)
            return find_node(node->left, n);
        return false;
    }
    else
    {
        if (node->right != NULL)
            return find_node(node->right, n);
        return false;
    }
}

void create_depth_list(TreeNode *node, int level)
{
    if (node != NULL)
    {
        if (levelnodes.size() > 0 && level < levelnodes.size())
        {
            ListNode *headlevel = levelnodes[level];
            ListNode *newnode;
            newnode = new ListNode(node->val);
            newnode->next = headlevel;
            headlevel = newnode;
            levelnodes[level] = headlevel;
        }
        else
        {
            ListNode *newnode;
            newnode = new ListNode(node->val);
            levelnodes.push_back(newnode);
        }

        create_depth_list(node->left, level + 1);
        create_depth_list(node->right, level + 1);
    }
}

int main()
{
    TreeNode *root;
    root = new TreeNode(21);

    insert_node(root, 15);
    insert_node(root, 12);
    insert_node(root, 25);
    insert_node(root, 23);
    insert_node(root, 8);

    // inorder_traversal(root);
    // cout << endl;

    // preorder_traversal(root);
    // cout << endl;

    // postorder_traversal(root);
    // cout << endl;

    // cout << find_node(root, 100) << endl;

    create_depth_list(root, 0);

    for (int i = 0; i < levelnodes.size(); i++)
    {
        ListNode *cur = levelnodes[i];
        cout << "Level " << i << endl;
        while (cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
        cout << "=====" << endl;
    }

    return 0;
}
