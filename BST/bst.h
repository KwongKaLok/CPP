template <typename T>
class BST
{
private:    
    struct BSTnode
    {
        T value;
        BST left;
        BST right;
        BSTnode(const T &x) : value(x) {}
        BSTnode(const BSTnode &) = default;
        ~BSTnode() { cout << "delete " << value << endl; }
    };
    BSTnode *root = nullptr;

public:
    BST() = default;
    ~BST() { delete root; }
    BST(BST &&bst)
    {
        root = bst.root;
        bst.root = nullptr;
    }
    BST(const BST &bst)
    {
        if (bst.is_empty())
            return;
        root = new BSTnode(*bst.root);
    }
    bool is_empty() const { return root == nullptr; }
    bool contains(const T &x) const;
    void print(int depth = 0) const;
    const T &find_max() const; // Find the maximum value
    const T &find_min() const; // Find the minimum value

    void insert(const T &); // Insert an item with a policy
    void remove(const T &); // Remove an item
};