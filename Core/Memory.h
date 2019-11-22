#ifndef MEMORY_H
#define MEMORY_H

#include <memory>
#include "RawPtr.h"

template<typename _T>
class WeakPtr : public std::weak_ptr<_T>
{
public:
    template<typename... _Args>
    WeakPtr(_Args&&... args)
        : std::weak_ptr<_T>(args...)
    {
    }
    
    inline RawPtr<_T> raw() { return this->get(); }

    inline bool is_null() const { return !this->get(); }
    inline bool is_not_null() const { return this->get(); }

    inline const RawPtr<_T> raw() const { return this->get(); }
};

template<typename _T>
class RefPtr : public std::shared_ptr<_T>
{
public:
    template<typename... _Args>
    static RefPtr make(_Args&&... args)
    {
        return std::make_shared<_T>(args...);
    }
    
    template<typename... _Args>
    RefPtr(_Args&&... args)
        : std::shared_ptr<_T>(args...)
    {
    }

    inline bool is_null() const { return !this->get(); }
    inline bool is_not_null() const { return this->get(); }

    inline RawPtr<_T> raw() { return this->get(); }
    inline const RawPtr<_T> raw() const { return this->get(); }
    inline WeakPtr<_T> weak_ptr() { return WeakPtr<_T>(this); }
};

template<typename _T>
class OwnPtr : public std::unique_ptr<_T>
{
public:
    template<typename... _Args>
    OwnPtr(_Args&&... args)
        : std::unique_ptr<_T>(args...)
    {
    }
    
    template<typename... _Args>
    static OwnPtr&& make(_Args&&... args)
    {
        return std::move(OwnPtr(new _T(args...)));
    }

    inline bool is_null() const { return this->get(); }
    inline bool is_not_null() const { return this->get(); }

    inline RawPtr<_T> raw() { return this->get(); }
    inline const RawPtr<_T> raw() const { return this->get(); }
};

#endif // MEMORY_H
