#ifndef SHADER_H
#define SHADER_H

#include "../Global.h"
#include "../IO/Path.h"
#include "../Application.h"
#include "../GenericResource.h"

extern class Shader* new_gl_shader(const Path& path);

class Shader
{
public:
    virtual inline const char* class_name() const { return "Shader"; }
    template<typename... _Args>
    static RefPtr<Shader> construct(_Args&&... args)
    {
        switch (Application::backend_implementation)
        {
        case BackendImplementation::SFML:
            ASSERT(false);
            break;
        case BackendImplementation::GL:
            return RefPtr<Shader>(new_gl_shader(std::forward<_Args>(args)...));
            break;
        }
        ASSERT(false /* not implemented */);
        return nullptr;
    }

    virtual ~Shader();
    
protected:
    Shader();
};

#endif // SHADER_H
