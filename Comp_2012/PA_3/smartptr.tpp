// TODO: Implement the member functions of SmartPtr (Part (A), except the output operator)
template <typename T>
SmartPtr<T>::SmartPtr()
{
    ptr = nullptr;
    count = nullptr;
}

template <typename T>
SmartPtr<T>::SmartPtr(const T &val)
{
    ptr = new T{val};
    count = new unsigned int{1};
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &that)
{
    this->ptr = that.ptr;
    this->count = that.count;
    if (this->ptr != nullptr)
        *count += 1;
}

template <typename T>
SmartPtr<T>::~SmartPtr()
{
    if (ptr != nullptr)
    {
        if (*count == 1)
        {
            delete ptr;
            delete count;
            ptr = nullptr;
            count = nullptr;
        }
        else
            *count = *count - 1;
    }
}

template <typename T>
SmartPtr<T> &SmartPtr<T>::operator=(const SmartPtr<T> &that)
{
    if (ptr != nullptr)
    {
        if (*count == 1)
        {
            delete this->ptr;
            delete this->count;
        }
        else if (*count > 1)
        {
            *count = *count - 1;
        }
    }
    ptr = that.ptr;
    count = that.count;
    if (that.ptr != nullptr)
    {
        *count = *count + 1;
    }

    return (*this);
}

template <typename T>
void SmartPtr<T>::set(const T &val)
{
    if (ptr != nullptr)
    {

        if (*count == 1)
        {
            delete this->ptr;
            delete this->count;
        }
        else if (*count > 1)
        {
            *count = *count - 1;
        }
    }
    ptr = new T(val);
    count = new unsigned int(1);
}

template <typename T>
void SmartPtr<T>::unset()
{
    if (ptr != nullptr)
    {
        if (*count == 1)
        {
            delete this->ptr;
            delete this->count;
        }
        else if (*count > 1)
        {
            *count = *count - 1;
        }
    }
    this->ptr = nullptr;
    this->count = nullptr;
}

template <typename T>
bool SmartPtr<T>::is_null() const
{
    if (ptr == nullptr)
        return true;
    else
        return false;
}

template <typename T>
bool SmartPtr<T>::operator==(const SmartPtr<T> &that) const
{
    if (ptr == that.ptr)
        return true;
    else
        return false;
}

template <typename T>
bool SmartPtr<T>::operator!=(const SmartPtr<T> &that) const
{
    if (ptr == that.ptr)
        return false;
    else
        return true;
}
template <typename T>
T &SmartPtr<T>::operator*() const
{
    return (*ptr);
}
template <typename T>
T *SmartPtr<T>::operator->() const
{
    return ptr;
}