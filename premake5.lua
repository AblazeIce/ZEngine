workspace "Z"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--创建一个相对于解决方案的目录
IncludeDir={}
IncludeDir["GLFW"]="Z/vendor/GLFW/include"
IncludeDir["Glad"]="Z/vendor/Glad/include"
IncludeDir["ImGui"]="Z/vendor/imgui"

include "Z/vendor/GLFW"
include "Z/vendor/Glad"
include "Z/vendor/imgui"


project "Z"
	location "Z"
	kind "SharedLib" 
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "zpch.h"
	pchsource "Z/res/zpch.cpp"

	files 
	{
		"%{prj.name}/res/**.h",
		"%{prj.name}/res/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/res",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"Z_PLATFORM_WINDOWS",
			"Z_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	
	postbuildcommands{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "Z_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "Z_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "Z_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleAPP"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/res/**.h",
		"%{prj.name}/res/**.cpp"
	}
	includedirs
	{
		"Z/vendor/spdlog/include",
		"Z/res"
	}
	
	links
	{
		"Z"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"Z_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "Z_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "Z_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "Z_DIST"
		buildoptions "/MD"
		optimize "On"