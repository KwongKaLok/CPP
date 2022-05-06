template <typename T>
Node<T>::Node(const T& val) : val(val), out(nullptr), capacity(0), size_p(0) {
    return;
}

template <typename T>
Node<T>::Node(const Node<T>& that) : val(*that), out(nullptr), capacity(0), size_p(0) {
    return;
}

template <typename T>
Node<T>::~Node() {
    delete [] out;
    return;
}

template <typename T>
T& Node<T>::operator*() {
    return val;
}

template <typename T>
const T& Node<T>::operator*() const {
    return val;
}

template <typename T>
unsigned int Node<T>::degree() const {
    unsigned int res = 0;
    for ( unsigned int i = 0; i < size_p; ++i )
        res += !out[i].is_null();
    return res;
}

template <typename T>
unsigned int Node<T>::size() const {
    return size_p;
}

template <typename T>
SmartPtr<Node<T>> Node<T>::operator[](unsigned int i) const {
    return out[i];
}

template <typename T>
void Node<T>::add(SmartPtr<Node<T>> n) {
    if ( !n.is_null() && &*n != this && !exists(n) ) {
        if ( size_p == capacity ) {
            unsigned int new_capacity = capacity == 0 ? init_capacity : 2 * capacity;
            SmartPtr<Node<T>>* temp = new SmartPtr<Node<T>> [new_capacity];
            for ( unsigned int i = 0; i < capacity; ++i )
                temp[i] = out[i];
            delete [] out;
            out = temp;
            capacity = new_capacity;
        }
        out[size_p++] = n;
    }
    return;
}

template <typename T>
void Node<T>::remove(SmartPtr<Node<T>> n) {
    if ( !n.is_null() ) {
        for ( unsigned int i = 0; i < size_p; ++i )
            if ( out[i] == n )
                out[i].unset();
    }
    return;
}

template <typename T>
bool Node<T>::exists(SmartPtr<Node<T>> n) const {
    if ( !n.is_null() ) {
        for ( unsigned int i = 0; i < size_p; ++i )
            if ( out[i] == n )
                return true;
    }
    return false;
}

template <typename T>
SmartPtr<Node<T>> Node<T>::find(T val) const {
    for ( unsigned int i = 0; i < size_p; ++i )
        if ( !out[i].is_null() && **out[i] == val )
            return out[i];
    return SmartPtr<Node<T>>{};
}

template <typename T>
SmartPtr<Node<T>> new_node(const T& val) {
    return SmartPtr<Node<T>>{Node<T>{val}};
}

template <typename T>
void remove_node(SmartPtr<Node<T>> n) {
    if ( !n.is_null() ) {
        unsigned int size = n->size();
        for ( unsigned int i = 0; i < size; ++i )
            remove_edge(n, (*n)[i]);
    }
    return;
}

template <typename T>
void add_edge(SmartPtr<Node<T>> n1, SmartPtr<Node<T>> n2) {
    if ( !n1.is_null() && !n2.is_null() ) {
        n1->add(n2);
        n2->add(n1);
    }
    return;
}

template <typename T>
void remove_edge(SmartPtr<Node<T>> n1, SmartPtr<Node<T>> n2) {
    if ( !n1.is_null() && !n2.is_null() ) {
        n1->remove(n2);
        n2->remove(n1);
    }
    return;
}

// "depth-last search"
// disgusting trick: using Node<T> as a set of SmartPtr<Node<T>>
template <typename T, typename U>
SmartPtr<Node<T>> dls(SmartPtr<Node<T>> root, U pred) {
    return root.is_null() ? SmartPtr<Node<T>>{} : dls(root, pred, SmartPtr<Node<T>>{*root});
}

template <typename T, typename U>
SmartPtr<Node<T>> dls(SmartPtr<Node<T>> root, U pred, SmartPtr<Node<T>> visited) {
    visited->add(root);
    unsigned int size = root->size();
    for ( unsigned int i = 0; i < size; ++i ) {
        SmartPtr<Node<T>> n {(*root)[i]};
        if ( !n.is_null() && !visited->exists(n) ) {
            SmartPtr<Node<T>> res {dls(n, pred, visited)};
            if ( !res.is_null() )
                return res;
        }
    }
    if ( pred(root) )
        return root;
    return SmartPtr<Node<T>>{};
}

template <typename T>
void remove_graph(SmartPtr<Node<T>> root) {
    dls(root, [](SmartPtr<Node<T>> n) { remove_node(n); return false; });
    return;
}

template <typename T>
SmartPtr<Node<T>> find(SmartPtr<Node<T>> root, T val) {
    return dls(root, [val](SmartPtr<Node<T>> n) { return **n == val; });
}

template <typename T>
bool reachable(SmartPtr<Node<T>> root, SmartPtr<Node<T>> dest) {
    return !dls(root, [dest](SmartPtr<Node<T>> n) { return n == dest; }).is_null();
}



// alternative: BFS using set and queue
/* template <typename T>
bool operator<(const SmartPtr<T>& sp1, const SmartPtr<T>& sp2) {
    return sp1.operator->() < sp2.operator->();
}

template <typename T, typename U>
SmartPtr<Node<T>> bfs(SmartPtr<Node<T>> root, U pred) {
    set<SmartPtr<Node<T>>> s;
    queue<SmartPtr<Node<T>>> q;
    if ( !root.is_null() ) {
        s.insert(root);
        q.push(root);
    }
    while ( !q.empty() ) {
        SmartPtr<Node<T>> v (q.front());
        q.pop();
        unsigned int size (v->size());
        for ( unsigned int i (0); i < size; ++i ) {
            SmartPtr<Node<T>> w ((*v)[i]);
            if ( !w.is_null() && s.count(w) == 0 ) {
                s.insert(w);
                q.push(w);
            }
        }
        if ( pred(v) )
            return v;
    }
    return SmartPtr<Node<T>>();
}

template <typename T>
void remove_graph(SmartPtr<Node<T>> root) {
    bfs(root, [](SmartPtr<Node<T>> n) { remove_node(n); return false; });
    return;
}

template <typename T>
SmartPtr<Node<T>> find(SmartPtr<Node<T>> root, T val) {
    return bfs(root, [val](SmartPtr<Node<T>> n) { return **n == val; });
}

template <typename T>
bool reachable(SmartPtr<Node<T>> root, SmartPtr<Node<T>> dest) {
    return !bfs(root, [dest](SmartPtr<Node<T>> n) { return n == dest; }).is_null();
} */
