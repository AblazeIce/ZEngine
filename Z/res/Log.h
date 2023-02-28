#pragma once
//#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Z {
	class Z_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define Z_CORE_TRACE(...) ::Z::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define Z_CORE_INFO(...)  ::Z::Log::GetCoreLogger()->info(__VA_ARGS__)
#define Z_CORE_WARN(...)  ::Z::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define Z_CORE_ERROR(...) ::Z::Log::GetCoreLogger()->error(__VA_ARGS__)
#define Z_CORE_FATAL(...) ::Z::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define Z_TRACE(...)      ::Z::Log::GetClientLogger()->trace(__VA_ARGS__)
#define Z_INFO(...)       ::Z::Log::GetClientLogger()->info(__VA_ARGS__)
#define Z_WARN(...)       ::Z::Log::GetClientLogger()->warn(__VA_ARGS__)
#define Z_ERROR(...)      ::Z::Log::GetClientLogger()->error(__VA_ARGS__)
#define Z_FATAL(...)      ::Z::Log::GetClientLogger()->fatal(__VA_ARGS__)
