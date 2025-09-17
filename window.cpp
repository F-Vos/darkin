#include "window.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace darkin
{
    static int g_glfw_refcount = 0;

    window::~window()
    {
        destroy();
        if (--g_glfw_refcount == 0)
        {
            glfwTerminate();
        }
    }

    void window::create(const window_config& cfg)
    {
        if (g_glfw_refcount++ == 0)
        {
            if (!glfwInit())
            {
                g_glfw_refcount = 0;
                throw std::runtime_error("glfwInit failed");
            }
        }

        if (cfg.api == backend::vulkan)
        {
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        }
        else
        {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        }

        glfwWindowHint(GLFW_RESIZABLE, cfg.resizable ? GLFW_TRUE : GLFW_FALSE);
        glfwWindowHint(GLFW_VISIBLE, cfg.visible ? GLFW_TRUE : GLFW_FALSE);

        handle_ = glfwCreateWindow(
            static_cast<int>(cfg.width),
            static_cast<int>(cfg.height),
            cfg.title,
            nullptr,
            nullptr
        );

        if (!handle_)
        {
            if (--g_glfw_refcount == 0) glfwTerminate();
            throw std::runtime_error("glfwCreateWindow failed");
        }

        if (cfg.api == backend::opengl)
        {
            glfwMakeContextCurrent(handle_);
        }
    }

    void window::destroy()
    {
        if (handle_)
        {
            glfwDestroyWindow(handle_);
            handle_ = nullptr;
        }
    }

    void window::show()
    {
        if (handle_) glfwShowWindow(handle_);
    }

    void window::hide()
    {
        if (handle_) glfwHideWindow(handle_);
    }

    void window::poll()
    {
        glfwPollEvents();
    }

    bool window::should_close() const
    {
        return handle_ ? glfwWindowShouldClose(handle_) : true;
    }

    void window::set_framebuffer_size_cb(void (*cb)(GLFWwindow*, int, int))
    {
        glfwSetFramebufferSizeCallback(handle_, cb);
    }

    window_snapshot window::snapshot() const
    {
        window_snapshot s{};
        if (!handle_) return s;
        glfwGetWindowPos(handle_, &s.x, &s.y);
        glfwGetWindowSize(handle_, &s.w, &s.h);
        s.maximized = glfwGetWindowAttrib(handle_, GLFW_MAXIMIZED) == GLFW_TRUE;
        return s;
    }

    void window::set_geometry(const window_snapshot& s)
    {
        if (!handle_) return;
        if (s.maximized)
        {
            glfwMaximizeWindow(handle_);
        }
        else
        {
            glfwSetWindowPos(handle_, s.x, s.y);
            glfwSetWindowSize(handle_, s.w, s.h);
        }
    }

    void window::recreate(const window_config& cfg)
    {
        auto s = snapshot();
        destroy();
        auto tmp = cfg;
        tmp.visible = false;      // create hidden to avoid flicker
        create(tmp);
        set_geometry(s);
        show();
    }
}
