#pragma once


#ifdef POD_PLATFORM_WINDOWS

extern Pod::Application* Pod::CreateApplication();

int main(int argc, char** argv) {
	auto app = Pod::CreateApplication();
	app->Run();
	delete app;
}

#endif // POD_PLATFORM_WINDOWS
