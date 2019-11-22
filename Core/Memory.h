#ifndef MEMORY_H
#define MEMORY_H

#include <memory>
#include "RawPtr.h"

template<typename _T>
class WeakPtr : public std::weak_ptr<_T>
{
public:
    inline RawPtr<_T> raw() { return this->get(); }
    inline const RawPtr<_T> raw() const { return this->get(); }
};

template<typename _T>
class RefPtr : public std::shared_ptr<_T>
{
public:
    template<typename... _Args>
    static RefPtr make(_Args&&... args)
    {
        return std::make_shared(std::forward(args)...);
    }
    
    inline RawPtr<_T> raw() { return this->get(); }
    inline const RawPtr<_T> raw() const { return this->get(); }
    inline WeakPtr<_T> weak() { return WeakPtr<_T>(this); }
};

template<typename _T>
class OwnPtr : public std::unique_ptr<_T>
{
public:
    template<typename... _Args>
    static OwnPtr make(_Args&&... args)
    {
        return std::make_shared(std::forward(args)...);
    }
    
    inline RawPtr<_T> raw() { return this->get(); }
    inline const RawPtr<_T> raw() const { return this->get(); }
};

#endif // MEMORY_H
