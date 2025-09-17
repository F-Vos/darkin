#include "vk_window.h"

// std
#include <stdexcept>

namespace Darkin::Vk
{

	VkWindow::VkWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name }
	{
		initWindow();
	}

	VkWindow::~VkWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void VkWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
		//glfwSetWindowUserPointer(window, this);
		//glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
	}

	void VkWindow::pollEvents()
	{
		glfwPollEvents();
	}

	bool VkWindow::shouldClose() const
	{
		return glfwWindowShouldClose(window);
	}

	//void VkWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	//{
	//	if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
	//	{
	//		throw std::runtime_error("failed to craete window surface");
	//	}
	//}

	//void VkWindow::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
	//    auto VkWindow = reinterpret_cast<VkWindow*>(glfwGetWindowUserPointer(window));
	//    VkWindow->framebufferResized = true;
	//    VkWindow->width = width;
	//    VkWindow->height = height;
	//}

}  // namespace Darkin::Vk