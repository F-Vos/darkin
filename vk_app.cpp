#include "vk_app.h"

// libs

// std
#include <array>
#include <cassert>
#include <chrono>
#include <stdexcept>

namespace Darkin::Vk
{
	VkApp::VkApp()
	{
	}

	VkApp::~VkApp()
	{
	}

	void VkApp::run()
	{
		while (!window.shouldClose())
		{
			window.pollEvents();
		}

	}
}  // namespace Darkin::Vk