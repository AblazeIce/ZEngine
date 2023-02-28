#include <Z.h>

class ExampleLayer :public Z::Layer
{
public:
	ExampleLayer()
		:Layer("Example") {}
	void OnUpdate() override
	{
		//Z_INFO("ExampleLayer::Update");
		if (Z::Input::isKeyPressed(Z_KEY_TAB))
			Z_TRACE("Tab key is pressed(poll)!");
	}
	void OnEvent(Z::Event& event) override
	{
		//Z_TRACE("{0}", event);
		if (event.GetEventType() == Z::EventType::KeyPressed)
		{
			Z::KeyPressedEvent& e = (Z::KeyPressedEvent&)event;
			if (e.GetKeyCode() == Z_KEY_TAB)
				Z_TRACE("Tab key is pressed (event)!");
			Z_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};
class Sandbox :public Z::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Z::ImGuiLayer());
	}
	~Sandbox() {};

private:
};
Z::Application* Z::CreateApplication() {
	return new Sandbox();
}