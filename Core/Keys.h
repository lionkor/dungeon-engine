#ifndef KEYS_H
#define KEYS_H

#include <GLFW/glfw3.h>
#include "Global.h"

enum Key
{
    A = 0,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    Num0,
    Num1,
    Num2,
    Num3,
    Num4,
    Num5,
    Num6,
    Num7,
    Num8,
    Num9,
    Escape,
    LControl,
    LShift,
    LAlt,
    LSystem,
    RControl,
    RShift,
    RAlt,
    RSystem,
    Menu,
    LBracket,
    RBracket,
    Semicolon,
    Comma,
    Period,
    Quote,
    Slash,
    Backslash,
    Tilde,
    Equal,
    Hyphen,
    Space,
    Enter,
    Backspace,
    Tab,
    PageUp,
    PageDown,
    End,
    Home,
    Insert,
    Delete,
    Add,
    Subtract,
    Multiply,
    Divide,
    Left,
    Right,
    Up,
    Down,
    Numpad0,
    Numpad1,
    Numpad2,
    Numpad3,
    Numpad4,
    Numpad5,
    Numpad6,
    Numpad7,
    Numpad8,
    Numpad9,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    Pause,
};

inline static Key key_from_glfw_key(int glfw_key)
{
    switch (glfw_key)
    {
    case GLFW_KEY_ESCAPE:
        return Key::Escape;
    default:
        LOG(__FUNCTION__ << ": "
                         << " not implemented: case " << glfw_key);
        break;
    }
}

inline static int glfw_key_from_key(Key key)
{
    switch (key)
    {
    case Key::Escape:
        return GLFW_KEY_ESCAPE;
    case Key::A:
        return GLFW_KEY_A;
    case Key::B:
        return GLFW_KEY_B;
    case Key::C:
        return GLFW_KEY_C;
    case Key::D:
        return GLFW_KEY_D;
    case Key::E:
        return GLFW_KEY_E;
    default:
        LOG(__FUNCTION__ << ": "
                         << " not implemented: case " << key);
        return GLFW_KEY_UNKNOWN;
    }
}

#endif // KEYS_H
