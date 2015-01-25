solution "ntd"
    configurations {"debug"}
    language "C++"

    includedirs "ntd/include"

    buildoptions "-std=c++1y"

    -- remove ldflags to fix broken dead code elimination stuff
    premake.gcc.platforms.ldflags = nil

    configuration "debug"
      flags {"Symbols"}

    project "ntd"
        kind "SharedLib"

        files "ntd/source/**.cpp"

    project "unit_tests"
        kind "ConsoleApp"
        links {"ntd"}

        files "tests/**.cpp"

