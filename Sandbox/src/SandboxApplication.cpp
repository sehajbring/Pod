
#include <Pod.h>

class Sandbox : public Pod::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Pod::Application* Pod::CreateApplication() {
	return new Sandbox();
}