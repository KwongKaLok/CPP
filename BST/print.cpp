template <typename T>
void BST<T>::print(int depth) const
{
    if (is_empty())
    {
        return;
    }
    root->right.print(depth + 1);
    for (int i = 0; i < depth; i++)
        cout << '\t';
    cout << root->value << endl;
    root->left.print(depth + 1);
}