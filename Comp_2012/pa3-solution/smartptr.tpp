template <typename T>
SmartPtr<T>::SmartPtr() : ptr(nullptr), count(nullptr) {
    return;
}

template <typename T>
SmartPtr<T>::SmartPtr(const T& val) : ptr(new T {val}), count(new unsigned int {1}) {
    return;
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& that) : ptr(that.ptr), count(that.count) {
    if ( !is_null() )
        *count += 1;
    return;
}

template <typename T>
SmartPtr<T>::~SmartPtr() {
    if ( !is_null() && --*count == 0 ) {
        delete ptr;
        delete count;
    }
    return;
}

template <typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& that) {
    if ( &that != this ) {
        this->~SmartPtr();
        ptr = that.ptr;
        count = that.count;
        if ( !is_null() )
            *count += 1;
    }
    return *this;
}

template <typename T>
void SmartPtr<T>::set(const T& val) {
    if ( &val != ptr ) {
        this->~SmartPtr();
        ptr = new T {val};
        count = new unsigned int {1};
    }
    return;
}

template <typename T>
void SmartPtr<T>::unset() {
    this->~SmartPtr();
    ptr = nullptr;
    count = nullptr;
    return;
}

template <typename T>
bool SmartPtr<T>::is_null() const {
    return ptr == nullptr;
}

template <typename T>
bool SmartPtr<T>::operator==(const SmartPtr<T>& that) const {
    return ptr == that.ptr;
}

template <typename T>
bool SmartPtr<T>::operator!=(const SmartPtr<T>& that) const {
    return ptr != that.ptr;
}

template <typename T>
T& SmartPtr<T>::operator*() const {
    return *ptr;
}

template <typename T>
T* SmartPtr<T>::operator->() const {
    return ptr;
}
