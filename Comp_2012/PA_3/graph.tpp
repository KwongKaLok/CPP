// TODO: Implement the member functions of Node (Part (B), except the output operator)
//             and the graph operations (Part (C))
template <typename T>
Node<T>::Node(const T &val)
{
    this->val = val;
    this->out = nullptr;
    this->capacity = 0;
    this->size_p = 0;
}

template <typename T>
Node<T>::Node(const Node<T> &that)
{
    val = that.val;
    out = nullptr;
    capacity = 0;
    size_p = 0;
}

template <typename T>
Node<T>::~Node()
{
    // for (unsigned int i = 0; i < capacity; i++)
    //     delete out[i];
    delete[] out;
}

template <typename T>
T &Node<T>::operator*()
{
    return val;
}

template <typename T>
const T &Node<T>::operator*() const
{
    return val;
}

template <typename T>
unsigned int Node<T>::degree() const
{
    unsigned int total = 0;
    for (unsigned int i = 0; i < capacity; i++)
    {
        if (!(out[i].is_null()))
            total++;
    }
    return total;
}

template <typename T>
unsigned int Node<T>::size() const
{
    return size_p;
}

template <typename T>
SmartPtr<Node<T> > Node<T>::operator[](unsigned int i) const
{
    return this->out[i];
}

template <typename T>
void Node<T>::add(SmartPtr<Node<T> > n)
{
    if (!n.is_null() && &(*n) != &*this)
    {
        bool exist = false;
        for (unsigned int i = 0; i < capacity; i++)
        {
            if (out[i] == n)
            {
                exist = true;
                break;
            }
        }
        if (!exist)
        {
            if (out == nullptr)
            {
                capacity = init_capacity;
                out = new SmartPtr<Node<T> >[init_capacity];
                for (unsigned int i = 0; i < init_capacity; i++)
                {
                    out[i] = SmartPtr<Node<T> >{};
                }
            }
            else if (size_p == capacity)
            {
                unsigned int n_capacity = 0;
                if (capacity >= init_capacity)
                {
                    n_capacity = capacity * 2;
                }
                else
                {
                    n_capacity = init_capacity * 2;
                }
                SmartPtr<Node<T> > *tmp = new SmartPtr<Node<T> >[n_capacity];
                for (unsigned int i = 0; i < capacity; i++)
                {
                    tmp[i] = out[i];
                }
                for (unsigned int i = capacity; i < n_capacity; i++)
                {
                    tmp[i] = SmartPtr<Node<T> >{};
                }
                delete[] out;
                out = tmp;
                capacity = n_capacity;
            }
            out[size_p] = n;
            size_p++;
        }
    }
}

template <typename T>
void Node<T>::remove(SmartPtr<Node<T> > n)
{
    if (!n.is_null())
    {
        for (unsigned int i = 0; i < size_p; i++)
        {
            if (out[i] == n)
            {
                out[i].unset();
                break;
            }
        }
    }
}

template <typename T>
bool Node<T>::exists(SmartPtr<Node<T> > n) const
{
    if (!n.is_null())
    {
        for (unsigned int i = 0; i < size_p; i++)
        {
            if (out[i] == n)
            {
                return true;
            }
        }
    }
    return false;
}

template <typename T>
SmartPtr<Node<T> > Node<T>::find(T val) const
{
    for (unsigned int i = 0; i < size_p; i++)
    {
        if (out[i]->val == val)
        {
            return out[i];
        }
    }
    return SmartPtr<Node<T> >{};
}

template <typename T>
SmartPtr<Node<T> > new_node(const T &val)
{
    Node<T> temp_node = Node<T>(val);
    return SmartPtr<Node<T> >(temp_node);
}

template <typename T>
void remove_node(SmartPtr<Node<T> > n)
{
    if (!n.is_null())
    {
        for (unsigned int i = 0; i < n->size(); i++)
        {
            if (!(*n)[i].is_null())
            {
                ((*n)[i])->remove(n);
                n->remove((*n)[i]);
            }
        }
    }
}

template <typename T>
void add_edge(SmartPtr<Node<T> > n1, SmartPtr<Node<T> > n2)
{
    if (!(n1.is_null() || n2.is_null() || n1 == n2))
    {
        n1->add(n2);
        n2->add(n1);
    }
}

template <typename T>
void remove_edge(SmartPtr<Node<T> > n1, SmartPtr<Node<T> > n2)
{
    if (!(n1.is_null() || n2.is_null() || n1 == n2))
    {
        n1->remove(n2);
        n2->remove(n1);
    }
}

template <typename T>
void remove_graph(SmartPtr<Node<T> > root)
{
    if (!(root.is_null()))
    {
        for (unsigned int i = 0; i < root->size(); i++)
        {
            if (!((*root)[i].is_null()))
            {
                remove_node((*root)[i]);
            }
        }
    }
}

template <typename T>
SmartPtr<Node<T> > recursion(SmartPtr<Node<T> > root, T val, SmartPtr<Node<T> > check)
{
    if (*(*root) == val)
    {
        return root;
    }
    else
    {
        check->add(root);
        for (unsigned int i = 0; i < root->size(); i++)
        {
            if (!((*root)[i].is_null()) && !(check->exists((*root)[i])))
            {
                if (*(*((*root)[i])) == val)
                {
                    return ((*root)[i]);
                }

                SmartPtr<Node<T> > temp = recursion((*root)[i], val, check);
                if (!(temp.is_null()))
                {
                    return temp;
                }
            }
        }
        return SmartPtr<Node<T> >{};
    }
}

template <typename T>
SmartPtr<Node<T> > find(SmartPtr<Node<T> > root, T val)
{
    SmartPtr<Node<T> > check{new_node(val)};
    return recursion(root, val, check);
}

template <typename T>
bool reachable(SmartPtr<Node<T> > root, SmartPtr<Node<T> > dest)
{
    if (!(root.is_null()) && !(dest.is_null()))
    {
        SmartPtr<Node<T> > temp = find(root, *(*dest));
        return !(temp.is_null());
    }
    return false;
}