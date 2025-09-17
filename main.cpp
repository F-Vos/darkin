
#include "vk_app.h"
#include "gl_app.h"


// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    Darkin::Gl::GlApp gl_app{};
    Darkin::Vk::VkApp vk_app{};


    try
    {
        gl_app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    try
    {
        vk_app.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}













































//#define GLFW_INCLUDE_VULKAN
//#define GLFW_INCLUDE_NONE 
//#include <GLFW/glfw3.h>
//#include <glad/glad.h>
//
//
//#include <iostream>
//#include <stdexcept>
//#include <cstdlib>
//
//const uint32_t WIDTH = 800;
//const uint32_t HEIGHT = 600;

//class DarkinEngine
//{
//public:
//	void run()
//	{
//		glfwInit();
//		initVulkanWindow();
//		initVulkan();
//		initGLWindow();
//		initGL();
//		mainLoop();
//		cleanup();
//	}
//
//private:
//	GLFWwindow* vk_window = nullptr;
//	GLFWwindow* gl_window = nullptr;
//
//
//	VkInstance instance;
//
//	void initVulkanWindow()
//	{
//		glfwDefaultWindowHints();
//		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
//		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
//
//		vk_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
//		if (!vk_window) throw std::runtime_error("Failed to create Vulkan window");
//	}
//
//	void initVulkan()
//	{
//		createVulkanInstance();
//	}
//
//	void initGLWindow()
//	{
//		glfwDefaultWindowHints();
//		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//		gl_window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL", nullptr, nullptr);
//		if (!gl_window) throw std::runtime_error("Failed to create OpenGL window");
//		glfwMakeContextCurrent(gl_window);
//	}
//
//	void initGL()
//	{
//		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//		{
//			throw std::runtime_error("Failed to initialize GLAD");
//		}
//		// Simple clear color so we see something
//		glViewport(0, 0, WIDTH, HEIGHT);
//		glClearColor(0.1f, 0.1f, 0.12f, 1.0f);
//	}
//
//	void mainLoop()
//	{
//		while (vk_window || gl_window)
//		{
//			glfwPollEvents();
//
//			if (vk_window && glfwWindowShouldClose(vk_window))
//			{
//				glfwDestroyWindow(vk_window);
//				vk_window = nullptr;
//				// Leave the Vulkan instance alive; cleanup() will take care of it.
//			}
//			if (gl_window && glfwWindowShouldClose(gl_window))
//			{
//				glfwDestroyWindow(gl_window);
//				gl_window = nullptr;
//			}
//
//			// Render GL if the window still exists
//			if (gl_window)
//			{
//				glfwMakeContextCurrent(gl_window);
//				glClear(GL_COLOR_BUFFER_BIT);
//				glfwSwapBuffers(gl_window);
//			}
//
//			// If you had Vulkan rendering, do it here while vk_window is valid
//		}
//	}
//
//	void cleanup()
//	{
//		vkDestroyInstance(instance, nullptr);
//
//		glfwDestroyWindow(gl_window);
//		glfwDestroyWindow(vk_window);
//
//		glfwTerminate();
//	}
//
//	void createVulkanInstance()
//	{
//		VkApplicationInfo appInfo{};
//		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
//		appInfo.pApplicationName = "Hello Triangle";
//		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
//		appInfo.pEngineName = "No Engine";
//		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
//		appInfo.apiVersion = VK_API_VERSION_1_0;
//
//		VkInstanceCreateInfo createInfo{};
//		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
//		createInfo.pApplicationInfo = &appInfo;
//
//		uint32_t glfwExtensionCount = 0;
//		const char** glfwExtensions;
//		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
//
//		createInfo.enabledExtensionCount = glfwExtensionCount;
//		createInfo.ppEnabledExtensionNames = glfwExtensions;
//
//		createInfo.enabledLayerCount = 0;
//
//		if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
//		{
//			throw std::runtime_error("failed to create instance!");
//		}
//	}
//};
//
//int main()
//{
//	DarkinEngine app;
//
//	try
//	{
//		app.run();
//	}
//	catch (const std::exception& e)
//	{
//		std::cerr << e.what() << std::endl;
//		return EXIT_FAILURE;
//	}
//
//	return EXIT_SUCCESS;
//}
