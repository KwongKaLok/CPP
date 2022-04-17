// TODO: Implement the member functions of SmartPtr (Part (A), except the output operator)
template <typename T>

SmartPtr<T>::SmartPtr()
{
    ptr = nullptr;
    count = nullptr;
}

SmartPtr<T>::SmartPtr(const T &val)
{
    T *instance = new T;
    instance = &val;
    count = new int;
    *count = 1;
}

SmartPtr<T>::SmartPtr(const SmartPtr<T>& that)
{
    ptr = that.ptr;
    that.count+=1;
}