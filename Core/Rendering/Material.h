#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Global.h"
#include "Texture.h"
#include "Color.h"
#include "../Application.h"

extern class Material* new_sfml_material(const RefPtr<Texture>&, const Color&);

class Material
{
public:
    virtual inline const char* class_name() const { return "Material"; }
    template<typename... _Args>
    static RefPtr<Material> construct(_Args&&... args)
    {
        switch (Application::backend_implementation)
        {
        case BackendImplementation::SFML:
            return RefPtr<Material>(new_sfml_material(std::forward<_Args>(args)...));
            break;
        }
        ASSERT(false /* not implemented */);
        return nullptr;
    }

    virtual ~Material();

    virtual RefPtr<Texture>       texture();
    virtual const RefPtr<Texture> texture() const;

    virtual Color color() const;
    virtual void  set_color(const Color& color);

protected:
    Material(const RefPtr<Texture>&, const Color&);

    RefPtr<Texture> m_texture;
    Color           m_color;
};

#endif // MATERIAL_H
