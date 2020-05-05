#include "..\headers\Example.hpp"
#include <SFMLApplication.hpp>

EXAMPLE_API const char* test()
{
    OpenGLRender3D::SFMLApplication app("../../assets/scene/scene.xml");
    app.start();

    return "Hello world. Este codigo se esta ejecutando desde una dll.";
}
