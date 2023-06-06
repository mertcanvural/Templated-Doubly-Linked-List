#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
ZLL<T>::ZLL()
{
    head = nullptr;
    tail = nullptr;
    iterator = nullptr;
}

template <typename T>
bool ZLL<T>::isEmpty()
{
    return (this->head == nullptr);
}

template <typename T>
bool ZLL<T>::empty()
{
    if (this->isEmpty())
        return true;
    Node<T> *nodeToDelete = this->head;
    Node<T> *nextNode;
    while (nodeToDelete != nullptr)
    {
        nextNode = nodeToDelete->next;
        remove(nodeToDelete);
        nodeToDelete = nextNode;
    }
    this->head = nullptr;
    this->tail = nullptr;
    return true;
}

template <typename T>
bool ZLL<T>::front(const T &value)
{
    if (typeid(value) != typeid(head->data))
    {
        cout << "Types differ for: " << head->data << " and " << value << "." << endl;
        return false;
    }
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return true;
}

template <typename T>
bool ZLL<T>::back(const T &value)
{
    if (typeid(value) != typeid(head->data))
    {
        cout << "Types differ for: " << head->data << " and " << value << "." << endl;
        return false;
    }
    Node<T> *newNode = new Node<T>(value);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    return true;
}

template <typename T>
bool ZLL<T>::join(ZLL<T> &other)
{
    if (this == &(other))
        return true;
    if (other.head != nullptr)
    {
        if (this->head != nullptr)
        {
            other.head->prev = this->tail;
            this->tail->next = other.head;
            this->tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        else
        {
            this->head = other.head;
            other.head = nullptr;
            this->tail = other.tail;
            other.tail = nullptr;
        }
    }
    return true;
}

template <typename T>
ZLL<T> &ZLL<T>::operator+=(const ZLL<T> &other)
{
    if (this == &other)
    {
        return *(this);
    }
    Node<T> *currNode = other.head;
    while (currNode != nullptr)
    {
        T value = currNode->data;
        this->back(value);
        currNode = currNode->next;
    }
    return *(this);
}

template <typename T>
ZLL<T> &ZLL<T>::operator-=(const ZLL<T> &other)
{
    if (this == &other)
    {
        return *(this);
    }
    Node<T> *currNode1 = this->head;
    Node<T> *currNode2 = other.head;

    while (currNode2 != nullptr)
    {
        while (currNode1 != nullptr)
        {
            if (currNode1->data == currNode2->data)
            {
                Node<T> *nodeToDelete = currNode1;
                currNode1 = currNode1->next;
                remove(nodeToDelete);
            }
            else
            {
                currNode1 = currNode1->next;
            }
        }
        currNode2 = currNode2->next;
        currNode1 = this->head;
    }
    return *(this);
}

template <typename T>
int ZLL<T>::removeZany()
{
    int zanyCount = 0;
    Node<T> *currNode = this->head;
    while (currNode != nullptr)
    {
        if (isZany(currNode->data))
        {
            Node<T> *nodeToDelete = currNode;
            currNode = currNode->next;
            remove(nodeToDelete);
            ++zanyCount;
        }
        else
        {
            currNode = currNode->next;
        }
    }
    return zanyCount;
}

template <typename T>
int ZLL<T>::removeNonZany()
{
    int nonZanyCount = 0;
    Node<T> *currNode = this->head;
    while (currNode != nullptr)
    {
        if (!isZany(currNode->data))
        {
            Node<T> *nodeToDelete = currNode;
            currNode = currNode->next;
            remove(nodeToDelete);
            ++nonZanyCount;
        }
        else
        {
            currNode = currNode->next;
        }
    }
    return nonZanyCount;
}

template <typename T>
bool ZLL<T>::promoteZany()
{
    ZLL<T> nonZanyList;
    Node<T> *currNode = this->head;
    while (currNode != nullptr)
    {
        if (!isZany(currNode->data))
        {
            nonZanyList.front(currNode->data);
            Node<T> *nodeToDelete = currNode;
            currNode = currNode->next;
            remove(nodeToDelete);
        }
        else
        {
            currNode = currNode->next;
        }
    }
    this->join(nonZanyList);
    currNode = this->head;
    return true;
}

template <typename T>
void ZLL<T>::remove(Node<T> *currNode)
{
    Node<T> *succNode = currNode->next;
    Node<T> *predNode = currNode->prev;

    if (succNode != nullptr)
    {
        succNode->prev = predNode;
    }
    if (predNode != nullptr)
    {
        predNode->next = succNode;
    }
    if (head == currNode)
    {
        head = succNode;
    }
    if (tail == currNode)
    {
        tail = predNode;
    }
    currNode->next = nullptr;
    currNode->prev = nullptr;

    delete currNode;
}

template <typename T>
void ZLL<T>::show()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
bool ZLL<T>::start()
{
    iterator = head;
    return (iterator != nullptr);
}

template <typename T>
T &ZLL<T>::getNext()
{
    Node<T> *currNode = iterator;
    iterator = iterator->next;
    return (currNode->data);
}

template <typename T>
bool ZLL<T>::done()
{
    if (iterator == nullptr)
        return true;
    return false;
}

template <typename T>
ZLL<T>::~ZLL()
{
    this->empty();
}