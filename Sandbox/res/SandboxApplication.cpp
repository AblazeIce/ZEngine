
#include <Z.h>

class ExampleLayer:public Z::Layer
{
public:
	ExampleLayer()
		:Layer("Example"){}
	void OnUpdate() override
	{
		Z_INFO("ExampleLayer::Update");
	}
	void OnEvent(Z::Event& event) override
	{
		Z_TRACE("{0}", event);
	}
};
class Sandbox:public Z::Application
{
public:
	Sandbox(){
		
		PushLayer(new ExampleLayer());
		PushOverlay(new Z::ImGuiLayer());
	}
	~Sandbox() {};

private:

};
Z::Application* Z::CreateApplication() {
	return new Sandbox();
}
