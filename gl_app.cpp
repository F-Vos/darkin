#include "gl_app.h"

// libs

// std
#include <array>
#include <cassert>
#include <chrono>
#include <stdexcept>

namespace Darkin::Gl
{
	GlApp::GlApp()
	{
	}

	GlApp::~GlApp()
	{
	}

	void GlApp::run()
	{
		while (!window.shouldClose())
		{
			window.pollEvents();
			window.swapBuffers();
		}

	}
}  // namespace Darkin::Gl