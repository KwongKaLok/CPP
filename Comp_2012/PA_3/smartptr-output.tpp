// TODO: Implement the output operator<< for SmartPtr
template <typename T>
std::ostream& operator<<(std::ostream& os, const SmartPtr<T>& sp)
{
    if (sp.ptr!=nullptr)
        os<<"SmartPtr("<<*sp<<","<<*sp.count<<")";
    else
        os<<"SmartPtr()";
    return os;
}