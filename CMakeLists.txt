cmake_minimum_required(VERSION 3.16)

include_directories(include)
link_directories(lib)

project(dungeon-engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS 2a)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -s")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(dungeon-engine main.cpp
    Core/GenericResource.cpp
    Core/GUID.cpp
    Core/IO/Path.cpp
    Core/IO/File.cpp
    Core/Rendering/Texture.cpp
    Core/Rendering/Material.cpp
    Core/Window.cpp
    Core/Rendering/Renderer.cpp
    Core/Application.cpp
    Core/GameState.cpp
    Core/State.cpp
    Core/ECS/Entity.cpp
    Core/ECS/Transform.cpp
    Core/ECS/SpriteRenderComponent.cpp
    Core/sfml/SFMLBackend.cpp
    Core/sfml/SFMLMaterial.cpp
    Core/sfml/SFMLTexture.cpp
)


target_link_libraries(dungeon-engine 
    sfml-window-s
    sfml-graphics-s 
    sfml-system-s
    sfml-audio-s
    stdc++fs
    dl
    Xrandr
    udev
    X11
    String
)

