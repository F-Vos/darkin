#pragma once

struct GLFWwindow;

#include <string>

namespace Darkin::Gl
{
	class GlWindow
	{
	public:
		GlWindow(int w, int h, std::string name);
		~GlWindow();

		GlWindow(const GlWindow&) = delete;
		GlWindow& operator=(const GlWindow&) = delete;

		void pollEvents();
		void swapBuffers();
		bool shouldClose() const;

		//VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }
		//bool wasWindowResized() { return framebufferResized; }
		//void resetWindowResizedFlag() { framebufferResized = false; }
		GLFWwindow* getGLFWwindow() const { return window; }

		//void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);


	private:
		//static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
		void initWindow();
		void initOpenGL();

		int width;
		int height;
		bool framebufferResized = false;

		std::string windowName;
		GLFWwindow* window;
	};
}  // namespace Darkin::Gl