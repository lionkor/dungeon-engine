#ifndef SFMLMATERIAL_H
#define SFMLMATERIAL_H

#include "../Global.h"
#include "../Material.h"

class SFMLMaterial : public Material
{
public:
    SFMLMaterial();
    
    virtual bool has_texture() const override;
    virtual RefPtr<Texture> texture() override;
    virtual const RefPtr<Texture> texture() const override;
    virtual void set_texture(const RefPtr<Texture>& texture) override;
    virtual void set_texture(const Path& path) override;
    virtual void set_texture(const GenericResource& res) override;
protected:
    
};

#endif // SFMLMATERIAL_H
