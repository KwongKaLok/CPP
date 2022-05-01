#ifndef BSTMAP_H
#define BSTMAP_H

#include <iostream>
#include <assert.h>

using namespace std;

template <typename K, typename V> 
struct Pair
{ 
    K key;
    V value;
};

template <typename K, typename V> 
class BSTMap 
{
  private:
    // A node in a binary search tree
    struct MapItem 
    {
        Pair<K,V> data;
        BSTMap left;        // Left sub-tree or called left child
        BSTMap right;       // Right sub-tree or called right child
        MapItem(const MapItem&) = default; // Copy constructor
        ~MapItem() = default; 
        MapItem(const K& k, const V& v): data{k,v} { };
    };

    MapItem* root = nullptr;
    
  public:
    BSTMap() = default;           // Empty BSTMap
    ~BSTMap() { delete root; }    // Actually recursive

    // Deep copy using copy constructor
    BSTMap(const BSTMap& bst) {
        if (bst.is_empty())
            return;

        root = new MapItem(*bst.root);  // Recursive
    }

    //Given
    bool is_empty() const;

    bool contains(const K& x) const;
            
    void remove(const K& x);

    void insert(const K& k, const V& v);

    const Pair<K, V>& find_min() const;

    const Pair<K, V>& find_max() const;

    //Todo
    V operator[](const K& k) const;

    V& operator[] (const K& k);

    BSTMap& operator=(const BSTMap& bst);

    int size() const;

    void clear();

    template <typename K_, typename V_> 
    friend ostream& operator<<(ostream& os, const BSTMap<K_, V_>& bst);
};

#include "bstmap-todo.tpp"
#include "bstmap-given.tpp"

#endif