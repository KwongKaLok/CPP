//TODO: Return reference to value in this map corresponding to the provided key. 
//If the provided key does not exist, print an error message "Key is not in BSTMap" to std::cerr and terminate program using exit(-1).
// In practice, one should check if the map contains the key before calling this operator[]
template <typename K, typename V>
V& BSTMap<K, V>::operator[] (const K& k) {

}


//TODO: Return value in this map corresponding to the provided key. 
//If the provided key does not exist, print an error message "Key is not in BSTMap" to std::cerr and terminate program using exit(-1).
// In practice, one should check if the map contains the key before calling this operator[]
template <typename K, typename V>
V BSTMap<K, V>::operator[](const K& k) const {

} 


//TODO: Assignment constructor, pay attention to memory leak
//Before doing assignment, you need to first check whether this != &bst, 
//if the two pointers are equal then you need to do nothing. 
//You also need to clear the original Map before doing assignment, we will check memory leak in this lab.
template <typename K, typename V>
BSTMap<K, V>& BSTMap<K, V>::operator=(const BSTMap& bst) {             

}


//TODO: Return number of items in this map
template <typename K, typename V>
int BSTMap<K, V>::size() const {

}


//TODO: Clear all items in BSTMap
template <typename K, typename V>
void BSTMap<K, V>::clear() {

}


//TODO: In-Order Traversal
template <typename K, typename V>
ostream& operator<<(ostream& os, const BSTMap<K, V>& bst) {

}
