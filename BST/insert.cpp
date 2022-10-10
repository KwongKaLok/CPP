template <typename T>
void BST<T>::insert(const T &x)
{
    if (is_empty())
        root = new BSTnode(x);
    else if (x < root->value)
        root->left.insert(x);
    else if (x > root->value)
        root->right.insert(x);
}