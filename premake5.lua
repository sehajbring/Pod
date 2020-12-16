workspace "Pod"
    startproject "Sandbox"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pod"
	location "Pod"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/3rdparty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"POD_PLATFORM_WINDOWS",
			"POD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "POD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POD_DIST"
        optimize "On"
    

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pod/3rdparty/spdlog/include",
		"Pod/src"
	}

	links
	{
		"Pod"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"POD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "POD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POD_DIST"
        optimize "On" 
    
