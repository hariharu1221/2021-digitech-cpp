#pragma once

template<typename T>
class cMyDoubleList_Node
{
public:
    T data;
    cMyDoubleList_Node<T>* prev;
    cMyDoubleList_Node<T>* next;

public:
    cMyDoubleList_Node(T value = T())
        : data(value), prev(nullptr), next(nullptr)
    {
    }
};

template<typename T>
class cMyList_iterator
{
public:
    cMyDoubleList_Node<T>* p;

public:
    cMyList_iterator(cMyDoubleList_Node<T>* _p = nullptr)
        : p(_p)
    {
    }

    T& operator*()
    {
        return p->data;
    }

    T* operator->()
    {
        return &(p->data);
    }

    cMyList_iterator<T>& operator++() noexcept {
        p = p->next;
        return *this;
    }

    cMyList_iterator<T> operator++(int) noexcept {
        cMyList_iterator<T> result = *this;
        p = p->next;
        return result;
    }

    cMyList_iterator<T>& operator--() noexcept {
        p = p->prev;
        return *this;
    }

    cMyList_iterator<T> operator--(int) noexcept {
        cMyList_iterator<T> result = *this;
        p = p->prev;
        return result;
    }

    bool operator==(const cMyList_iterator<T>& _other)
    {
        return p == _other.p;
    }

    bool operator!=(const cMyList_iterator<T>& _other)
    {
        return p != _other.p;
    }
};

template<typename T>
class cMyList
{
private:
    cMyDoubleList_Node<T>* head;
    cMyDoubleList_Node<T>* tail;
    int list_size;
public:
    cMyList()
        : head(nullptr), tail(nullptr), list_size(0)
    {
    }

    cMyList(int count, T value = T())
        : head(nullptr), tail(nullptr), list_size(count)
    {
    }

    ~cMyList()
    {
        clear();
    }

    T& front()
    {
        return head->data;
    }

    T& back()
    {
        return tail->data;
    }

    bool empty()
    {
        return list_size == 0;
    }

    int size()
    {
        return list_size;
    }

    void clear()
    {
        list_size = 0;
        while (head != nullptr)
        {
            auto iter = head;
            head = head->next;
            delete iter;
        }
        head = tail = nullptr;
    }

    cMyList_iterator<T> insert(const cMyList_iterator<T>& pos, T value)
    {
        if (pos.p == nullptr)
        {
            if (head != nullptr)
                return nullptr;
            //head에 추가
            head = new cMyDoubleList_Node<T>(value);
            tail = head;

            list_size = 1;
            return head;
        }

        if (head == pos.p)
        {
            //head를 교체
            cMyDoubleList_Node<T>* last_head = head;
            head = new cMyDoubleList_Node<T>(value);
            head->next = last_head;
            last_head->prev = head;

            ++list_size;
            return head;
        }

        cMyDoubleList_Node<T>* new_node = new cMyDoubleList_Node<T>(value);
        new_node->next = pos.p;
        new_node->prev = pos.p->prev;
        pos.p->prev = new_node;

        ++list_size;
        return new_node;
    }

    cMyList_iterator<T> erase(const cMyList_iterator<T>& pos)
    {
        if (pos.p == nullptr)
        {
            return nullptr;
        }

        if (pos.p == head)
        {
            //head를 제거
            cMyDoubleList_Node<T>* last_head = head;
            head = head->next;
            delete last_head;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;

            --list_size;
            return head;
        }

        if (pos.p == tail)
        {
            //tail을 제거
            cMyDoubleList_Node<T>* last_tail = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete last_tail;

            --list_size;
            return nullptr;
        }

        cMyDoubleList_Node<T>* result_iter = pos.p->next;
        pos.p->prev->next = pos.p->next;
        pos.p->next->prev = pos.p->prev;
        delete pos.p;

        --list_size;
        return result_iter;
    }

    void push_back(T value)
    {
        //tail 뒤에 추가
        if (tail == nullptr)
            insert(head, value);
        else
        {
            cMyDoubleList_Node<T>* last_tail = tail;
            tail = new cMyDoubleList_Node<T>(value);
            tail->prev = last_tail;
            last_tail->next = tail;

            ++list_size;
        }
    }

    void push_front(T value)
    {
        insert(head, value);
    }

    void pop_back()
    {
        erase(tail);
    }

    void pop_front()
    {
        erase(head);
    }

    cMyList_iterator<T> begin()
    {
        return cMyList_iterator<T>(head);
    }

    cMyList_iterator<T> end()
    {
        return cMyList_iterator<T>();
    }
};

