cmake_minimum_required(VERSION 3.4)
project(myLibrary)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME}_SOURCE_DIR}/lib)

# defining version
set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)

# settting up project
include_directories("${PROJECT_SOURCE_DIR}")
add_library("${PROJECT_NAME}" myFunctions.cpp)

############################################################
# installing myLibrary
############################################################
install(TARGETS myLibrary DESTINATION lib)
install(FILES myFunctions.cpp DESTINATION include)

