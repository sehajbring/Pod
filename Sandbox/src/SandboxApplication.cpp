
#include <Pod.h>

class CheckLayer : public Pod::Layer {
public:
	CheckLayer() : Layer("Check") {

	}

	void OnUpdate() override {
		POD_INFO("CheckLayer::Update");
	}

	void OnEvent(Pod::Event& event) override {
		POD_TRACE("{0}", event);
	}
};


class Sandbox : public Pod::Application {
public:
	Sandbox() {
		PushLayer(new CheckLayer());
	}

	~Sandbox() {

	}
};

Pod::Application* Pod::CreateApplication() {
	return new Sandbox();
}