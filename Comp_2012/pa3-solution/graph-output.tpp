template <typename T>
ostream& operator<<(ostream& os, const Node<T>& n) {
    unsigned int i = 0;
    unsigned int size = n.size();
    os << "Node(" << *n << ",{";
    while ( i < size && n[i].is_null() )
        i += 1;
    if ( i < size ) {
        os << **(n[i]);
        while ( ++i < size )
            if ( !n[i].is_null() )
                os << "," << **(n[i]);
    }
    os << "})";
    return os;
}
