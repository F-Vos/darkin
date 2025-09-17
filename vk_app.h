#pragma once

#include "vk_window.h"

// std
#include <memory>
#include <vector>

namespace Darkin::Vk
{
	class VkApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		VkApp();
		~VkApp();

		VkApp(const VkApp&) = delete;
		VkApp& operator=(const VkApp&) = delete;

		void run();

	private:
		VkWindow window{ WIDTH, HEIGHT, "Vulkan Graphics" };
	};
}  // namespace Darkin::Vk