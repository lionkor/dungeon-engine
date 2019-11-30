#ifndef MEMORY_H
#define MEMORY_H

#include <memory>
#include "RawPtr.h"

template<typename _T>
class WeakPtr : public std::weak_ptr<_T>
{
public:
    template<typename... _Args>
    WeakPtr(_Args&&... args) : std::weak_ptr<_T>(args...)
    {
    }

    inline RawPtr<_T> raw() { return this->get(); }

    inline bool is_null() const { return !this->get(); }
    inline bool is_not_null() const { return this->get(); }
    inline operator bool() const { return this->get(); }

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
    RefPtr(_Args&&... args) : std::shared_ptr<_T>(args...)
    {
    }

    inline bool is_null() const { return !this->get(); }
    inline bool is_not_null() const { return this->get(); }
    inline operator bool() const { return this->get(); }

    inline RefPtr& operator=(const RefPtr& ptr)
    {
        std::shared_ptr<_T>::operator=(ptr);
        return *this;
    }

    template<typename _TConvertType>
    _TConvertType& as()
    {
        return reinterpret_cast<_TConvertType>(this->get());
    }

    template<typename _TConvertType>
    const _TConvertType& as() const
    {
        return reinterpret_cast<_TConvertType>(this->get());
    }

    inline RawPtr<_T> raw() { return this->get(); }
    inline const RawPtr<_T> raw() const { return this->get(); }
    inline WeakPtr<_T> weak_ptr() { return WeakPtr<_T>(this); }
};

template<typename _T>
class OwnPtr : public std::unique_ptr<_T>
{
public:
    template<typename... _Args>
    OwnPtr(_Args&&... args) : std::unique_ptr<_T>(args...)
    {
    }

    template<typename... _Args>
    static OwnPtr make(_Args&&... args)
    {
        return OwnPtr(new _T(args...));
    }

    inline bool is_null() const { return !this->get(); }
    inline bool is_not_null() const { return this->get(); }
    inline operator bool() const { return this->get(); }

    inline RawPtr<_T> raw() { return this->get(); }
    inline const RawPtr<_T> raw() const { return this->get(); }
};

#define OBJECT(x, ...)                                                                   \
public:                                                                                  \
    virtual inline const char* class_name() const { return #x; }                         \
    template<typename... _Args>                                                          \
    static OwnPtr<x> construct(_Args&&... args)                                          \
    {                                                                                    \
        return OwnPtr<x>(new x(std::forward<_Args>(args)...));                           \
    }                                                                                    \
                                                                                         \
    virtual ~x() __VA_ARGS__ {}

#define OBJECT_CAST_CTOR(x, y, ...)                                                      \
public:                                                                                  \
    virtual inline const char* class_name() const { return #x; }                         \
    template<typename... _Args>                                                          \
    static OwnPtr<y> construct(_Args&&... args)                                          \
    {                                                                                    \
        return OwnPtr<y>(new x(std::forward<_Args>(args)...));                           \
    }                                                                                    \
                                                                                         \
    virtual ~x() __VA_ARGS__ {}

#endif // MEMORY_H
