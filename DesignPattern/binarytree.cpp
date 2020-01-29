#include<iostream>
#include <string>

using namespace std;

struct TreeNode 
{
   int data;
   TreeNode * left;
   TreeNode * right;  
};

class TreeFormation
{

    public:

        enum class Traversal
        {
            PreOrder, InOrder, PostOrder
        };
        TreeFormation()
        {
            rootNode = nullptr;
        }
        bool find(int n)
        {
            int ret = false;
            if(rootNode == nullptr)
                ret = false;
            else 
            {
                TreeNode * temp = rootNode;
                while(temp != nullptr)
                {
                    if(n == temp->data)
                    {
                        ret= true;
                        break;
                    }
                    else if(n > temp->data)
                    {
                        temp = temp->right;
                    }
                    else 
                    {
                        temp = temp->left;
                    }
                }
            }
            return ret;
        }
        void addTreeNode(int n)
        {
            if(rootNode == nullptr)
            {
                rootNode = insert(n);
            }
            else 
            {
                TreeNode * temp  = rootNode;
                while(temp != nullptr )
                {
                    if(n > temp->data)
                    {
                        if(temp->right != nullptr)
                            temp = temp->right;
                        else 
                        {
                            temp->right = insert(n);
                            break;
                        }
                    }
                    else 
                    {
                        if(temp->left != nullptr)
                            temp = temp->left;
                        else 
                        {
                            temp->left = insert(n);
                            break;
                        }
                    }
                }
            }
        }

    


        void print(const TreeFormation::Traversal & travelType)
        {
            switch(travelType)
            {
                case  Traversal::PreOrder:
                    std::cout << "\n PreOrder Traversal .......";
                    preOrderTraversal(rootNode);
                    break;
                case  Traversal::PostOrder:
                    std::cout << "\n PostOrder Traversal........";
                    postOrderTraversal(rootNode);
                    break;
                case Traversal::InOrder:
                    std::cout << "\n Inorder Traversal..........";
                    inOrderTraversal(rootNode);
                    break;
            }
        }     
    private:

        TreeNode * insert(int data)
        {
            TreeNode * node =new TreeNode();
            (node)->data = data;
            (node)->left = nullptr;
            (node)->right = nullptr;
            return node;
        }

        void inOrderTraversal(TreeNode * start)
        {
           if(start == nullptr)
             return;
            inOrderTraversal(start->left);
             std::cout <<"\t" <<start->data;
            inOrderTraversal(start->right);
        }

        void preOrderTraversal(TreeNode * start)
        {
            if(start == nullptr)
                return;
            std::cout <<  "\t"<<start->data;
            preOrderTraversal(start->left);
            preOrderTraversal(start->right);
        }

        void postOrderTraversal(TreeNode * start)
        {
             if(start == nullptr)
                return;
            postOrderTraversal(start->left);
            postOrderTraversal(start->right);
            std::cout << "\t"<<start->data;
        }
        TreeNode * rootNode;
};

int main()
{
    TreeFormation tree;
    tree.addTreeNode(7);
    tree.addTreeNode(12);
    tree.addTreeNode(9);
    tree.addTreeNode(2);
    tree.addTreeNode(93);
    tree.addTreeNode(102);
    tree.addTreeNode(1027);
    tree.addTreeNode(24);
    tree.addTreeNode(230);
    tree.addTreeNode(24);
    tree.addTreeNode(87);
    tree.addTreeNode(29);
    tree.addTreeNode(4);
    
    tree.print(TreeFormation::Traversal::InOrder);
    tree.print(TreeFormation::Traversal::PostOrder);
    tree.print(TreeFormation::Traversal::PreOrder);

    if(tree.find(230))
    {
        std::cout << "\n230 is in the tree list";
    }

    if (tree.find(99999)) {
        /* code */
        std::cout << "\n Not found;";
    }
    

}