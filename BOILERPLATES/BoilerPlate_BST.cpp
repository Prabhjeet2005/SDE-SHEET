#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Tree
{
  int value;
  Tree *left;
  Tree *right;
  Tree(int value)
  {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

class Solution
{
  Tree *insert_tree(Tree *&root, int element)
  {
    if (root == nullptr)
    {
      Tree *new_node = new Tree(element);
      return new_node;
    }
    if (element < root->value)
    {
      root->left = insert_tree(root->left, element);
    }
    else
    {
      root->right = insert_tree(root->right, element);
    }

    return root;
  }

  void print_tree_level_order(Tree *&root)
  {
    if (root == nullptr)
    {
      cout << "Tree Empty" << "\n";
      return;
    }

    queue<Tree *> queue;
    queue.push(root);
    queue.push(nullptr);
    while (!queue.empty())
    {
      Tree *front = queue.front();
      queue.pop();

      if (front == nullptr)
      {
        if (!queue.empty())
        {
          queue.push(nullptr);
        }
        cout << "\n";
      }
      else
      {
        cout << front->value << " ";
        if (front->left != nullptr)
        {
          queue.push(front->left);
        }
        if (front->right != nullptr)
        {
          queue.push(front->right);
        }
      }
    }
  }

  void search_tree(Tree *&root, int element)
  {
    if (root == nullptr)
    {
      cout << "Element Not Found\n";
      return;
    }
    if (root->value == element)
    {
      cout << "Found Element\n";
      return;
    }
    if (element < root->value)
    {
      search_tree(root->left, element);
    }
    else
    {
      search_tree(root->right, element);
    }
  }

  Tree *find_inorder_successor(Tree *root)
  {
    if (root == nullptr || !root->right)
      return root;
    root = root->right;
    while (root != nullptr && root->left != nullptr)
    {
      root = root->left;
    }
    return root;
  }

  Tree *delete_from_tree(Tree *&root, int element)
  {
    if (root == nullptr)
    {
      return root;
    }
    if (root->value == element)
    {
      if (root->left == nullptr && root->right == nullptr)
      {
        // Leaf node
        delete root;
        return nullptr;
      }
      else if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr))
      {
        // 1 Child Node
        if (root->left != nullptr)
        {
          Tree *child = root->left;
          delete root;
          return child;
        }
        else if (root->right != nullptr)
        {
          Tree *child = root->right;
          delete root;
          return child;
        }
      }
      else
      {
        // 2 Child Node
        Tree *inorder_successor = find_inorder_successor(root);
        root->value = inorder_successor->value;
        root->right = delete_from_tree(root->right, inorder_successor->value);
        return root;
      }
    }
    if (element < root->value)
    {
      root->left = delete_from_tree(root->left, element);
    }
    else
    {
      root->right = delete_from_tree(root->right, element);
    }
    return root;
  }

  void print_inorder(Tree*& root){
    if(root == nullptr)return;
    print_inorder(root->left);
    cout<<root->value<<" ";
    print_inorder(root->right);
  }
  void print_preorder(Tree*& root)
  {
    if (root == nullptr)
      return;
    cout << root->value << " ";
    print_preorder(root->left);
    print_preorder(root->right);
  }
  void print_postorder(Tree*& root)
  {
    if (root == nullptr)
      return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->value << " ";
  }

public:
  void solution()
  {
    Tree *root = new Tree(50);
    insert_tree(root, 60);
    insert_tree(root, 70);
    insert_tree(root, 40);
    insert_tree(root, 45);
    insert_tree(root, 10);

    print_tree_level_order(root);
    cout << "\n";
    search_tree(root, 45);
    cout << "\nAFTER DELETION\n";
    delete_from_tree(root, 40);
    print_tree_level_order(root);
    cout<<"\nINORDER\n";
    print_inorder(root);
    cout<<"\nPREORDER\n";
    print_preorder(root);
    cout<<"\nPOSTORDER\n";
    print_postorder(root);
  }
};

int main()
{
  Solution sol = Solution();
  cout << "\n";
  sol.solution();
  cout << "\n";
}