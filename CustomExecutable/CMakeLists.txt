add_executable(ExGame custom_main.cpp)

target_include_directories(ExGame PUBLIC
    "../Include/3rdParty"
    "../Include/EXPGE"
    "../Include/EXPGE/stb"
    "../Include/3rdParty/AL"
    "../Include/3rdParty/bullet"
    "../Include/3rdParty/GLFW"
    "../Include/3rdParty/json"
)

link_directories("../Bins/Linux64/")

target_link_libraries(ExGame "libExpansionMath.so")
target_link_libraries(ExGame "libRaindropRenderer.so")
target_link_libraries(ExGame "libExpansionGameEngineCore.so")
target_link_libraries(ExGame "libPhysicaSound.so")
target_link_libraries(ExGame "libBulldozerFileManager.so")
