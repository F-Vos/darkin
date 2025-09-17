#pragma once

#include "gl_window.h"

// std
#include <memory>
#include <vector>

namespace Darkin::Gl
{
	class GlApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		GlApp();
		~GlApp();

		GlApp(const GlApp&) = delete;
		GlApp& operator=(const GlApp&) = delete;

		void run();

	private:
		GlWindow window{ WIDTH, HEIGHT, "OpenGL Graphics" };
	};
}  // namespace Darkin::Gl