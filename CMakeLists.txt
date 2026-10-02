cmake_minimum_required(VERSION 3.20)
project(game CXX)

set(CMAKE_CXX_STANDARD 20)

# Dependencias del proyecto
set(SKEL  ${CMAKE_SOURCE_DIR}/src)
set(PHYSX ${CMAKE_SOURCE_DIR}/packages/NVIDIA.PhysX.4.1.229882250/installed/x64-windows)
set(GLUT  ${CMAKE_SOURCE_DIR}/packages/freeglut.3.0.0.v140.1.0.2)

set(PHYSX_LIBS $<IF:$<CONFIG:Debug>,${PHYSX}/debug/lib,${PHYSX}/lib>)
set(GLUT_LIBS  ${GLUT}/runtimes/win-x64/native/$<IF:$<CONFIG:Debug>,Debug,Release>)

# Recursive .cpp compile
file(GLOB_RECURSE SRC CONFIGURE_DEPENDS ${SKEL}/*.cpp)

add_executable(game ${SRC})
target_include_directories(game PRIVATE ${SKEL} ${SKEL}/Scenes ${PHYSX}/include ${GLUT}/sources)
target_compile_definitions(game PRIVATE _HAS_EXCEPTIONS=0 _CRT_SECURE_NO_DEPRECATE RENDER_SNIPPET PHYSX_PROFILE_SDK
    $<IF:$<CONFIG:Debug>,PX_DEBUG=1;PX_CHECKED=1;PX_NVTX=1;PX_SUPPORT_PVD=1,PX_SUPPORT_PVD=0>)

# Enlazar todas las librerías de PhysX
target_link_directories(game PRIVATE ${PHYSX_LIBS} ${GLUT_LIBS})
target_link_libraries(game PRIVATE
    LowLevel_static_64 LowLevelAABB_static_64 LowLevelDynamics_static_64 PhysX_64
    PhysXCharacterKinematic_static_64 PhysXCommon_64 PhysXCooking_64 PhysXExtensions_static_64
    PhysXFoundation_64 PhysXPvdSDK_static_64 PhysXTask_static_64 PhysXVehicle_static_64
    SceneQuery_static_64 SimulationController_static_64
    $<IF:$<CONFIG:Debug>,freeglutd,freeglut>)

# El ejecutable va a bin/ junto a las DLL
set_target_properties(game PROPERTIES
    OUTPUT_NAME_DEBUG gameDEBUG
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin)
