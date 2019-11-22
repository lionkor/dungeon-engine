#include "Core/Global.h"
#include "Core/Application.h"

int main(int, char**)
{
    auto app = Application::construct(BackendType::SFML);
}

