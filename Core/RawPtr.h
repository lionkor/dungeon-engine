#ifndef RAWPTR_H
#define RAWPTR_H

#include <utility>

template<typename _T>
class RawPtr
{
public:
    RawPtr(_T* data) : data(data) {}
    RawPtr(const RawPtr& p) : data(p.data) {}
    RawPtr(RawPtr&& p) : data(std::move(p.data)) {}

    operator _T*() { return data; }
    operator const _T*() const { return data; }
    operator bool() { return data; }

    _T& operator*() { return *data; }
    const _T& operator*() const { return *data; }

    _T* operator->() { return data; }
    const _T* operator->() const { return data; }

protected:
    _T* data = nullptr;
};

#endif // RAWPTR_H
