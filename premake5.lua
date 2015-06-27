solution "ntd-unit-tests"
    configurations {"debug"}
    language "C++"

    includedirs "include"

    buildoptions "-std=c++1y"

    configuration "debug"
      flags {"Symbols"}

    project "unit_tests"
        kind "ConsoleApp"

        files "tests/**.cpp"

