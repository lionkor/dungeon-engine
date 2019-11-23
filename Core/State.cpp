#include "State.h"
#include "Application.h"
#include "Window.h"
#include "Rendering/Renderer.h"

Application& State::application() { return m_application; }

const Application& State::application() const { return m_application; }

Window& State::window() { return m_application.window(); }

const Window& State::window() const { return m_application.window(); }

Renderer& State::renderer() { return m_application.window().renderer(); }

const Renderer& State::renderer() const { return m_application.window().renderer(); }



RawPtr<Entity> State::get_entity(GUID guid) { NOTIMPL }
