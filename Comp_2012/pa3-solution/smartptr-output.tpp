template <typename T>
ostream& operator<<(ostream& os, const SmartPtr<T>& sp) {
    os << "SmartPtr(";
    if ( !sp.is_null() )
        os << *sp.ptr << "," << *sp.count;
    os << ")";
    return os;
}
