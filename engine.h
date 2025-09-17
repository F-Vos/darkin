#pragma once
#include "backend.h"
#include "window.h"

#include <variant>
#include <memory>

struct GLFWwindow;
class GLrenderer; // forward in cpp via header include
class VKrenderer;

namespace darkin
{
    class engine
    {
    public:
        explicit engine(const window_config& cfg);
        ~engine();

        void run();
        void switch_backend(backend new_api); // hot swap (via window recreate)

    private:
        static void framebuffer_size_cb(GLFWwindow* wnd, int w, int h);
        void on_resize(int w, int h);

        window win_;
        window_config cfg_;

        // store either renderer without interfaces
        std::variant<std::monostate, class GLrenderer, class VKrenderer> renderer_;
    };
}
