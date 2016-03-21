cmake_minimum_required(VERSION 3.4)
project(LearningCMake)

set(BIN_DIR ${${PROJECT_NAME}_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add version number
set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 1)
configure_file(
        "${PROJECT_SOURCE_DIR}/${PROJECT_NAME}Config.h.in"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

############################################################
# add myLibrary
############################################################
option (USE_MY_LIBRARY "Use myFunctions myLibrary" ON)
if (USE_MY_LIBRARY)
    add_subdirectory(mylibrary)
    set (EXTRA_LIBS ${EXTRA_LIBS} myLibrary)
endif (USE_MY_LIBRARY)
############################################################

set(SOURCE_FILES main.cpp)
add_executable(LearningCMake ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})


############################################################
# installing LearningCMake
############################################################
install(TARGETS LearningCMake DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h" DESTINATION include)


############################################################
# uninstalling LearningCMake
############################################################
CONFIGURE_FILE(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")
ADD_CUSTOM_TARGET(uninstall
        "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")