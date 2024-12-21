cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

file(GLOB SOURCE
	./*.h
	./*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})
