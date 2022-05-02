// TODO: Return reference to value in this map corresponding to the provided key.
// If the provided key does not exist, print an error message "Key is not in BSTMap" to std::cerr and terminate program using exit(-1).
//  In practice, one should check if the map contains the key before calling this operator[]
template <typename K, typename V>
V &BSTMap<K, V>::operator[](const K &k)
{
    if (is_empty()) // Base case #1
    {
        std::cerr << "Key is not in BSTMap\n";
        exit(-1);
    }

    if (root->data.key == k) // Base case #2
        return (root->data.value);

    else if (k < root->data.key) // Recursion on the left sub-tree
        return root->left.operator[](k);

    else // Recursion on the right sub-tree
        return root->right.operator[](k);
    
}

// TODO: Return value in this map corresponding to the provided key.
// If the provided key does not exist, print an error message "Key is not in BSTMap" to std::cerr and terminate program using exit(-1).
//  In practice, one should check if the map contains the key before calling this operator[]
template <typename K, typename V>
V BSTMap<K, V>::operator[](const K &k) const
{
    if (is_empty()) // Base case #1
    {
        std::cerr << "Key is not in BSTMap\n";
        exit(-1);
    }

    if (root->data.key == k) // Base case #2
        return (root->data.value);

    else if (k < root->data.key) // Recursion on the left sub-tree
        return root->left.operator[](k);

    else // Recursion on the right sub-tree
        return root->right.operator[](k);
}

// TODO: Assignment constructor, pay attention to memory leak
// Before doing assignment, you need to first check whether this != &bst,
// if the two pointers are equal then you need to do nothing.
// You also need to clear the original Map before doing assignment, we will check memory leak in this lab.
template <typename K, typename V>
BSTMap<K, V> &BSTMap<K, V>::operator=(const BSTMap &bst)
{

    if (this != &bst)
    {
        delete this->root;
        this->root = new MapItem(*bst.root);
    }
    return *this;
}

// TODO: Return number of items in this map
template <typename K, typename V>
int BSTMap<K, V>::size() const
{
    if (this->is_empty())
    {
        return 0;
    }
    return 1+(root->left.size())+(root->right.size());

}

// TODO: Clear all items in BSTMap
template <typename K, typename V>
void BSTMap<K, V>::clear()
{
    if (this->is_empty())
    {
        return;
    }else
    {
        root->left.clear();
        root->right.clear();
        this->remove(root->data.key);
    }
    
    
    
}

// TODO: In-Order Traversal
template <typename K, typename V>
ostream &operator<<(ostream &os, const BSTMap<K, V> &bst)
{
    if (bst.root)
    {
        os<<bst.root->left;
        if (!bst.root->left.is_empty())
        {
            os<<" , ";
        }
        os<<"{"<<bst.root->data.key<<":"<<bst.root->data.value<<"}";
        if (!bst.root->right.is_empty())
        {
            os<<" , ";
        }
        os<<bst.root->right;
        
    }
    return os;
}
