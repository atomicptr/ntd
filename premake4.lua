solution "ntd-unit-tests"
    configurations {"debug"}
    language "C++"

    includedirs "include"

    buildoptions "-std=c++1y"

    -- remove ldflags to fix broken dead code elimination stuff
    premake.gcc.platforms.ldflags = nil

    configuration "debug"
      flags {"Symbols"}

    project "unit_tests"
        kind "ConsoleApp"

        files "tests/**.cpp"

