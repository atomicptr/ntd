solution "ntd"
    configurations {"debug"}
    language "C++"

    includedirs "ntd/include"

    buildoptions "-std=c++1y"

    targetdir "bin"

    project "ntd"
        kind "SharedLib"

        files "ntd/source/**.cpp"

    project "tests"
        kind "ConsoleApp"
        links {"ntd", "mavis"}

        files "tests/**.cpp"

