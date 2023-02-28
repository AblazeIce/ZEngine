#pragma once

#include "Events/Event.h"
namespace Z
{
	class Z_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		//�����ջ
		virtual void OnAttach() {}
		//�Ƴ���ջ
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		//�����¼�
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}