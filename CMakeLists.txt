cmake_minimum_required(VERSION 3.15)

project(ThePankeyEngine_Support_Serialization)

if(NOT TARGET ThePankeyEngine_Support_Serialization)

    add_library(ThePankeyEngine_Support_Serialization INTERFACE)

    target_include_directories(
        ThePankeyEngine_Support_Serialization
          INTERFACE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif()

