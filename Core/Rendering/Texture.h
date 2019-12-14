#ifndef TEXTURE_H
#define TEXTURE_H

#include "../Global.h"
#include "../IO/Path.h"
#include "../Application.h"
#include "Color.h"

class GenericResource;

extern Texture* new_sfml_texture(const Path& path);
extern Texture* new_sfml_texture(const GenericResource& res);

class Texture : public GUID
{
public:
    friend class ImageFile;


    virtual inline const char* class_name() const { return "Material"; }
    template<typename... _Args>
    static RefPtr<Texture> construct(_Args&&... args)
    {
        switch (Application::backend_implementation)
        {
        case BackendImplementation::SFML:
            return RefPtr<Texture>(new_sfml_texture(std::forward<_Args>(args)...));
            break;
        }
        ASSERT(false /* not implemented */);
        return nullptr;
    }

    virtual ~Texture();

    virtual void load_from_file(const Path&)              = 0;
    virtual void load_from_memory(const GenericResource&) = 0;

    virtual SizeT width() const  = 0;
    virtual SizeT height() const = 0;

    virtual Color pixel_at(SizeT x, SizeT y)                       = 0;
    virtual void  set_pixel_at(SizeT x, SizeT y, const Color& col) = 0;

protected:
    Texture();
};


#endif // TEXTURE_H
