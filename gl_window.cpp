#include "gl_window.h"


// libs
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// std
#include <stdexcept>
#include <iostream>

namespace Darkin::Gl
{

	GlWindow::GlWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name }
	{
		initWindow();
		initOpenGL();
	}

	GlWindow::~GlWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void GlWindow::pollEvents()
	{
		glfwPollEvents();
	}

	bool GlWindow::shouldClose() const
	{
		return glfwWindowShouldClose(window);
	}

	void GlWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
		//glfwSetWindowUserPointer(window, this);
		//glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
		glfwMakeContextCurrent(window);

	}

	void GlWindow::initOpenGL()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw std::runtime_error("Failed to initialize GLAD");
		}
		// Simple clear color so we see something
		glViewport(0, 0, width, height);
		//glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		std::cout << "Hi Elen!! :3";
	}

	void GlWindow::swapBuffers()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}



	//void GlWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
	//    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
	//        throw std::runtime_error("failed to craete window surface");
	//    }
	//}

	//void GlWindow::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	//    auto GlWindow = reinterpret_cast<GlWindow*>(glfwGetWindowUserPointer(window));
	//    GlWindow->framebufferResized = true;
	//    GlWindow->width = width;
	//    GlWindow->height = height;
	//}

}  // namespace Darkin::Gl