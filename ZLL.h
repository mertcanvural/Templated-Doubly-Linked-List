#ifndef ZLL_H
#define ZLL_H

#include "Node.h"
#include "zany.h"
template <typename T>
class ZLL
{
public:
    ZLL();
    bool isEmpty();
    bool empty();

    bool front(const T &val);
    bool back(const T &val);

    bool join(ZLL<T> &other);
    ZLL<T> &operator+=(const ZLL<T> &other);
    ZLL<T> &operator-=(const ZLL<T> &other);

    int removeZany();
    int removeNonZany();
    bool promoteZany();

    bool start();
    bool done();
    T &getNext();

    void remove(Node<T> *currNode);
    void show();
    ~ZLL();

private:
    Node<T> *iterator;
    Node<T> *head;
    Node<T> *tail;
};
#include "ZLL.cpp"
#endif