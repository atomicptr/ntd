solution "ntd"
    configurations {"debug"}
    language "C++"

    includedirs "ntd/include"

    buildoptions "-std=c++1y"

    project "ntd"
        kind "SharedLib"

        files "ntd/source/**.cpp"

    project "unit_tests"
        kind "ConsoleApp"
        links {"ntd", "mavis"}

        files "tests/**.cpp"

