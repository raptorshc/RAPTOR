cmake_minimum_required ( VERSION 3.6 )
set ( PROJECT_NAME "SkyNet" )
project ( ${PROJECT_NAME} )

set ( SOURCE_FILES Connections.h Layer.h Neuron.h Neuron.cpp Skynet.h Skynet.cpp examples/SkynetExample/SkynetTestingMain.cpp Functions.cpp Functions.h Activations.h Activations.cpp )
set ( CMAKE_CXX_FLAGS "-Wall -O3 --std=c++11" )

add_executable ( ${PROJECT_NAME} ${SOURCE_FILES} )