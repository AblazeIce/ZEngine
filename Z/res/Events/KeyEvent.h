#pragma once
#include "Event.h"

//#include <sstream>
namespace Z
{
	class Z_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
			/*virtual int GetCategoryFlags() const override {
			return EventCategoryKeyboard |S EventCategoryInput;
			}*/
	protected:
		KeyEvent(int keycode)
			:m_KeyCode(keycode) {}
		int m_KeyCode;
	};
	class Z_API KeyPressedEvent :public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		inline int GetRepeatCount() const { return m_RepeatCount; }
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_KeyCode << "(" << m_RepeatCount << "repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
			/*static EventType GetStaticType() { return EventType::KeyPressed; }
			virtual EventType GetEventType() const override { return GetStaticType(); }
			virtual const char* GetName() const override { return "KeyPressed"; }*/
	private:
		int m_RepeatCount;
	};
	class Z_API KeyReleasedEvent :public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			:KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
	class Z_API KeyTypedEvent :public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent:" << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	};
}
