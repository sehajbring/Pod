#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pod {
	class POD_API Log
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

//Core logging macros
#define POD_CORE_ERROR(...) ::Pod::Log::GetCoreLogger()->error(__VA_ARGS__)
#define POD_CORE_WARN(...)  ::Pod::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define POD_CORE_INFO(...)  ::Pod::Log::GetCoreLogger()->info(__VA_ARGS__)
#define POD_CORE_TRACE(...) ::Pod::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define POD_CORE_FATAL(...) ::Pod::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client logging macros
#define POD_ERROR(...) ::Pod::Log::GetClientLogger()->error(__VA_ARGS__)
#define PODWARN(...)  ::Pod::Log::GetClientLogger()->warn(__VA_ARGS__)
#define POD_INFO(...)  ::Pod::Log::GetClientLogger()->info(__VA_ARGS__)
#define POD_TRACE(...) ::Pod::Log::GetClientLogger()->trace(__VA_ARGS__)
#define POD_FATAL(...) ::Pod::Log::GetClientLogger()->fatal(__VA_ARGS__)