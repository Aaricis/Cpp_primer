#include<iostream>
#include<string>
using namespace std;

class TreeNode{
    public:
        TreeNode():value(string()), count(0), left(NULL), right(NULL), use(new size_t(0)) {}
        TreeNode(const TreeNode& t): value(t.value), count(t.count), left(t.left), right(t.right), use(t.use) {++*use;}
        TreeNode& operator=(const TreeNode& rhs);
        ~TreeNode();
    private:
        string value;
        int count;
        TreeNode *left;
        TreeNode *right;
        size_t *use;
};

TreeNode& TreeNode::operator=(const TreeNode& rhs){
    ++*rhs.use;
    if(--*use==0){
        delete left;
        delete right;
        delete use;
    }
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

TreeNode::~TreeNode(){
    if(--*use==0){
        delete left;
        delete right;
        delete use;
    }
}

class BinStrTree{
    public:
    BinStrTree():root(new TreeNode()){}
    BinStrTree(const BinStrTree& bt):root(bt.root){}
    BinStrTree operator=(const BinStrTree& rhs){
        TreeNode* newroot = new TreeNode(*rhs.root);
        delete root;
        root = newroot;
        return *this;
    }
    ~BinStrTree(){
        delete root;
    }
    private:
        TreeNode *root;
};

int main(){
    return 0;
}

