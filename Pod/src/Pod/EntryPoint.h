#pragma once



#ifdef POD_PLATFORM_WINDOWS

extern Pod::Application* Pod::CreateApplication();

int main(int argc, char** argv) {

	Pod::Log::Init();
	POD_CORE_WARN("Initalized!");
	int a = 10;
	POD_INFO("Hello! Var={0}", a);
	auto app = Pod::CreateApplication();
	app->Run();
	delete app;
}

#endif // POD_PLATFORM_WINDOWS
