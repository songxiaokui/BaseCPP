set(CompileCPUMax_MakeCommand make -j${CPU_CORES})

if (BUILD_WITH_STATIC)
    set(LIBRARY_PREFIX ${CMAKE_STATIC_LIBRARY_PREFIX})
    set(LIBRARY_SUFFIX ${CMAKE_STATIC_LIBRARY_SUFFIX})
else ()
    set(LIBRARY_PREFIX ${CMAKE_SHARED_LIBRARY_PREFIX})
    set(LIBRARY_SUFFIX ${CMAKE_SHARED_LIBRARY_SUFFIX})
endif ()

# ---[ Threads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
list(APPEND PROJECT_LINKER_LIBS ${CMAKE_THREAD_LIBS_INIT})

# ---[ Event
set(EVENT_DirName "Event")
include(${CMAKE_EXTERNAL_PATH}/Event.cmake)
list(APPEND PROJECT_INCLUDE_DIRS ${EVENT_INCLUDE_DIRS})
list(APPEND PROJECT_LINKER_LIBS ${EVENT_LIBRARIES})