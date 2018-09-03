cmake_minimum_required(VERSION 3.0)

project(rpg_game)

set(source_folder ${PROJECT_SOURCE_DIR}/source/src)
set(header_folder ${PROJECT_SOURCE_DIR}/source/include)

set(sources 
    ${source_folder}/main.cpp
)

set(headers

)

set(third_party ${CMAKE_CURRENT_LIST_DIR}/../third_party)

set(include_dirs
    ${third_party}/SDL2/include
)

set(libraries
    SDL2-static
)

if (UNIX AND NOT APPLE)
	find_package(X11 REQUIRED)
	find_package(Threads REQUIRED)
	list(APPEND libraries
		${CMAKE_DL_LIBS}
		${CMAKE_THREAD_LIBS_INIT}
		${X11_LIBRARIES}
		${X11_Xxf86vm_LIB}
		GL
	)
endif()

if (WIN32)
    list(APPEND libs
        imm32.lib
        ole32.lib
        oleaut32.lib
        winmm.lib
        version.lib
        opengl32.lib
    )
endif()

# Setup executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/../deploy-build)
add_executable(${CMAKE_PROJECT_NAME} ${sources} ${headers})
target_link_libraries(${CMAKE_PROJECT_NAME} ${libraries})
include_directories(${include_dirs})
