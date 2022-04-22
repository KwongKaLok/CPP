// TODO: Implement the output operator<< for Node
template <typename T>
std::ostream &operator<<(std::ostream &os, const Node<T> &n)
{

    os << "Node(" << *n << ",{";
    if (n.size() != 0)
    {
        for (unsigned int i = 0; i < n.size(); i++)
        {
            if (!n[i].is_null())
            {
                if (i == 0)
                    os << "";
                else
                    os << ",";
                os << *(*n[i]);
            }
        }
    }    
    os<<"})";
    return os;
}