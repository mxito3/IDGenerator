cmake_minimum_required(VERSION 3.9.3)
set(PROJECT_NAME IDGenerator)
set(sources main.cpp  checkPermission.cpp peerControl.cpp)
set (CMAKE_CXX_STANDARD 11)



add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} /usr/lib/x86_64-linux-gnu/libcrypto.so curl)

if(WIN32)
    set(CPACK_GENERATOR ZIP)
else()
    set(CPACK_GENERATOR TGZ)
endif()
install(TARGETS ${PROJECT_NAME}  RUNTIME DESTINATION bin)
include (InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME})
include (CPack)