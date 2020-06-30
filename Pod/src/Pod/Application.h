#pragma once
#include "Core.h"

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
