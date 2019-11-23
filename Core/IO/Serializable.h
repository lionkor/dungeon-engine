#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "../Global.h"
#include "Path.h"
#include "File.h"

/// Interface for serialization
class Serializable
{
public:
    Serializable() {}
    virtual ~Serializable() {}

    virtual void serialize(File&) { NOTIMPL }
    virtual void deserialize(File&) { NOTIMPL }
};

#endif // SERIALIZABLE_H
