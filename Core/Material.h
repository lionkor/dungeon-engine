#ifndef MATERIAL_H
#define MATERIAL_H

#include "Global.h"
#include "Texture.h"

class Material
{
public:
    Material();

    inline bool has_texture() const { return m_texture.is_not_null(); }
    inline void set_texture(RefPtr<Texture>&& tex) { m_texture = std::move(tex); }
    
    inline RefPtr<Texture> texture()
    {
        ASSERT(m_texture.is_not_null());
        return m_texture;
    }
    
    inline const RefPtr<Texture> texture() const
    {
        ASSERT(m_texture.is_not_null());
        return m_texture;
    }

protected:
    RefPtr<Texture> m_texture;
};

#endif // MATERIAL_H
