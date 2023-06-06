#ifndef NODE_H
#define NODE_H

template <typename T>
class ZLL;

template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;
    Node<T> *prev;

public:
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    Node(const Node<T> &other)
    {
        other.data = data;
    }
    friend class ZLL<T>;

    template <typename TT>
    friend std::ostream &operator<<(std::ostream &os, const Node<TT> &node);
};
#endif

template <typename T>
std::ostream &operator<<(std::ostream &os, const Node<T> &node)
{
    os << node.data;
    return os;
}
