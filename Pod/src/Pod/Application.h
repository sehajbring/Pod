#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Pod {
	class POD_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//Defined in client
	Application* CreateApplication();

}
