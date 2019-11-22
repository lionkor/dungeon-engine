project(dungeon-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS 2a)
set(CMAKE_CXX_COMPILER clang++)

add_executable(dungeon-engine main.cpp
    Core/GenericResource.cpp
    Core/GUID.cpp
    Core/Path.cpp
    Core/Texture.cpp
    Core/Material.cpp
    Core/Window.cpp
    Core/Renderer.cpp
    Core/Application.cpp
    Core/sfml/SFMLRenderingBackend.cpp
    Core/sfml/SFMLMaterial.cpp
    Core/sfml/SFMLTexture.cpp
)

target_link_libraries(dungeon-engine sfml-window sfml-graphics sfml-system sfml-audio)
