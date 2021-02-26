add_library(ls-3d-premium-plus SHARED
    Character.cpp
    Character.h
    Explorer.cpp
    Explorer.h
)

target_include_directories(ls-3d-premium-plus PUBLIC
    "../Include/3rdParty"
    "../Include/EXPGE"
    "../Include/EXPGE/stb"
    "../Include/3rdParty/AL"
    "../Include/3rdParty/bullet"
    "../Include/3rdParty/GLFW"
    "../Include/3rdParty/json"
)

link_directories("../Bins/Linux64/")

target_link_libraries(ls-3d-premium-plus "libExpansionMath.so")
target_link_libraries(ls-3d-premium-plus "libRaindropRenderer.so")
target_link_libraries(ls-3d-premium-plus "libExpansionGameEngineCore.so")
target_link_libraries(ls-3d-premium-plus "libPhysicaSound.so")
target_link_libraries(ls-3d-premium-plus "libBulldozerFileManager.so")
