template <typename K, typename V>
const Pair<K, V>& BSTMap<K, V>::find_min() const {
    const MapItem* node = root;

    while (!node->left.is_empty()) // Look for the leftmost node
        node = node->left.root;

    return node->data;
}


template <typename K, typename V>
const Pair<K, V>& BSTMap<K, V>:: find_max() const {
    const MapItem* node = root;

    while (!node->right.is_empty()) // Look for the rightmost node
        node = node->right.root;

    return node->data;
}


template <typename K, typename V>
bool BSTMap<K, V>::contains(const K& x) const {
    if (is_empty())           // Base case #1
        return false;
    
    if (root->data.key == x)     // Base case #2
        return true;

    else if (x < root->data.key) // Recursion on the left sub-tree
        return root->left.contains(x);

    else                      // Recursion on the right sub-tree
        return root->right.contains(x);
}


// leftmost item of its right subtree
template <typename K, typename V>
void BSTMap<K, V>::remove(const K& x) {
    if (is_empty())             // Item is not found; do nothing
        return;
    
    if (x < root->data.key)        // Remove from the left subtree
        root->left.remove(x);
    else if (x > root->data.key)   // Remove from the right subtree
        root->right.remove(x);
    else if (root->left.root && root->right.root) { // Found node has 2 children
        root->data = root->right.find_min();
        root->right.remove(root->data.key); // min is copied; can be deleted now 
    }
    else { // Found node has 0 or 1 child
        MapItem* deleting_node = root; // Save the root to delete first
        root = (root->left.is_empty()) ? root->right.root : root->left.root;

        // Set subtrees to nullptr before removal due to recursive destructor
        deleting_node->left.root = deleting_node->right.root = nullptr;
        delete deleting_node;
    }
}


template <typename K, typename V>
void BSTMap<K, V>::insert(const K& k, const V& v) {
    if (is_empty())            // Find the spot
        root = new MapItem(k, v);

    else if (k < root->data.key)
        root->left.insert(k, v);  // Recursion on the left sub-tree

    else if (k > root->data.key)
        root->right.insert(k, v); // Recursion on the right sub-tree

    else // This line is optional; just for illustration
        root->data.value = v;
}


template <typename K, typename V>
bool BSTMap<K, V>::is_empty() const {
    return root == nullptr; 
} 