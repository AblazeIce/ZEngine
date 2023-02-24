#include "zpch.h"
#include "Application.h"

#include "Log.h"
#include "glad/glad.h"

namespace Z
{
	Application* Application::s_Instance = nullptr;


Application::Application() 
{
	//��ֹ���ֶ������
	Z_CORE_ASSERT(!s_Instance, "Application already exists!");
	s_Instance = this;
	//��������
	m_Window = std::unique_ptr<Window>(Window::Create());
	//���ô����¼��ص�����ΪOnEvent()
	m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
}
void Application::OnEvent(Event& e)
{
#pragma region �رմ��ڵ��¼�����
	EventDispatcher dispatcher(e);
	//����ص��¼�eΪWindowCloseEvent,�����Run()����(�رմ���);��ʹe.m_Handled=true(��ʾe�¼��ѱ�����)
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
	//Z_CORE_TRACE("{0}", e);
#pragma endregion

	//�����¼���LayerStack�Ӻ���ǰ����
	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
	{
		(*--it)->OnEvent(e);
		//���¼�������������
		if (e.m_Handled)
			break;
	}
}
void Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	//���øò�������ġ���ʼ��...
	layer->OnAttach();
}
void Application::PushOverlay(Layer* overlay)
{
	m_LayerStack.PushOverlay(overlay);
	//���øò�������ġ���ʼ��...
	overlay->OnAttach();
}
void Application::Run()
{
	while (m_Running)
	{
		//����ָ����ɫ�����������ֵ
		glClearColor(1, 0, 0.5, 1);
		//���������������ΪԤ��ֵ��
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
