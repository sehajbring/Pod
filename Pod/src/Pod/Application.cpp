#include "Application.h"
#include "Pod/Events/ApplicationEvent.h"
#include "Pod/Log.h"

namespace Pod {


	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			POD_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			POD_TRACE(e);
		}
		while (true);
	}
}