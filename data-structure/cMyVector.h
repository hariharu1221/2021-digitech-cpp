#pragma once

template<typename T>
class cMyVector
{
private:
    T* p;
    int now_size;
    int max_size;

public:
    cMyVector()
        : p(nullptr), now_size(0), max_size(0)
    {
    }

    cMyVector(int n, T value = T())
        : p(nullptr), now_size(n), max_size(n)
    {
        p = new T[n];
        for (int i = 0; i < n; ++i)
            p[i] = value;
    }

    T& operator[] (int idx)
    {
        if (idx >= now_size)
        {
            //ÀÎµ¦½º¸¦ ¹þ¾î³­ Á¢±Ù
        }
        return p[idx];
    }

    int size()
    {
        return now_size;
    }

    int capacity()
    {
        return max_size;
    }

    bool empty()
    {
        return now_size == 0;
    }

    void resize(int new_size, T value = T())
    {
        if (max_size < new_size)
        {
            delete p;
            p = new T[new_size];
            max_size = new_size;
        }

        now_size = new_size;
        for (int i = 0; i < new_size; ++i)
            p[i] = value;
    }

    void reserve(int new_cap)
    {
        if (max_size < new_cap)
        {
            max_size = new_cap;
            T* copy_p = p;
            p = new T[new_cap];

            for (int i = 0; i < now_size; ++i)
                p[i] = copy_p[i];

            delete copy_p;
        }
    }

    void clear()
    {
        now_size = 0;
    }

    void push_back(T value)
    {
        if (max_size == 0)
            reserve(1);
        else if (now_size == max_size)
            reserve(max_size * 2);

        p[now_size++] = value;
    }

    void insert(int idx, T value)
    {
        if (max_size == 0)
            reserve(1);
        else if (now_size == max_size)
            reserve(max_size * 2);

        for (int i = now_size++; i > idx; --i)
            p[i] = p[i - 1];
        p[idx] = value;
    }

    void pop_back()
    {
        if (now_size == 0)
            return;
        --now_size;
    }

    void erase(int idx)
    {
        if (now_size == 0)
            return;
        --now_size;
        for (int i = idx; i < now_size; ++i)
            p[i] = p[i + 1];
    }

    T* begin()
    {
        return p;
    }
    
    T* end()
    {
        return p + now_size;
    }
};

