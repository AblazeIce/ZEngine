#include "zpch.h"
#include "Application.h"

#include "Log.h"
#include "glad/glad.h"

namespace Z
{
	Application* Application::s_Instance = nullptr;


Application::Application() 
{
	//防止出现多个单例
	Z_CORE_ASSERT(!s_Instance, "Application already exists!");
	s_Instance = this;
	//创建窗口
	m_Window = std::unique_ptr<Window>(Window::Create());
	//设置窗口事件回调函数为OnEvent()
	m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
}
void Application::OnEvent(Event& e)
{
#pragma region 关闭窗口的事件处理
	EventDispatcher dispatcher(e);
	//如果回调事件e为WindowCloseEvent,则结束Run()函数(关闭窗口);并使e.m_Handled=true(表示e事件已被处理)
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
	//Z_CORE_TRACE("{0}", e);
#pragma endregion

	//触发事件，LayerStack从后往前调用
	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
	{
		(*--it)->OnEvent(e);
		//若事件被处理，则跳出
		if (e.m_Handled)
			break;
	}
}
void Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	//设置该层的上下文、初始化...
	layer->OnAttach();
}
void Application::PushOverlay(Layer* overlay)
{
	m_LayerStack.PushOverlay(overlay);
	//设置该层的上下文、初始化...
	overlay->OnAttach();
}
void Application::Run()
{
	while (m_Running)
	{
		//函数指定颜色缓冲区的清除值
		glClearColor(1, 0, 0.5, 1);
		//函数将缓冲区清除为预设值。
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();
		m_Window->OnUpdate();
	}
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}

Application::~Application() 
{
}

}
