#pragma once
#include "backend.h"
#include <cstdint>

struct GLFWwindow;

namespace darkin
{
    struct window_config
    {
        uint32_t width{ 800 };
        uint32_t height{ 600 };
        const char* title{ "darkin" };
        backend api{ backend::opengl };
        bool resizable{ true };
        bool visible{ true };
    };

    struct window_snapshot
    {
        int x{ 100 };
        int y{ 100 };
        int w{ 800 };
        int h{ 600 };
        bool maximized{ false };
    };

    class window
    {
    public:
        window() = default;
        ~window();

        void create(const window_config& cfg);
        void destroy();
    private:
    };
}
