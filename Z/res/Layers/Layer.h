#pragma once

#include "Events/Event.h"
namespace Z
{
	class Z_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		//推入堆栈
		virtual void OnAttach() {}
		//移出堆栈
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		//接受事件
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}