#ifndef RAWPTR_H
#define RAWPTR_H

#include <utility>

template<typename _T>
class RawPtr
{
public:
    RawPtr() : m_data(nullptr) {}
    RawPtr(_T* data) : m_data(data) {}
    RawPtr(const RawPtr& p) : m_data(p.m_data) {}
    // RawPtr(RawPtr&& p) : data(std::move(p.data)) {}

    // FIXME: add `as` method

    operator _T*() { return m_data; }
    operator const _T*() const { return m_data; }
    operator bool() { return m_data; }

    template<typename _TryT>
    _TryT& operator*()
    {
        return *m_data;
    }

    template<typename _TConvertType>
    _TConvertType& as()
    {
        return *(_TConvertType*)(m_data);
    }

    template<typename _TConvertType>
    _TConvertType* as_ptr()
    {
        return (_TConvertType*)(m_data);
    }

    template<typename _TryT>
    const _TryT& operator*() const
    {
        return *m_data;
    }

    _T*       operator->() { return m_data; }
    const _T* operator->() const { return m_data; }

    inline bool is_null() const { return !m_data; }
    inline bool is_not_null() const { return m_data; }

protected:
    _T* m_data = nullptr;
};

#endif // RAWPTR_H
