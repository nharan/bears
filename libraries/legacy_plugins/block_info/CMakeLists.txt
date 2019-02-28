file(GLOB HEADERS "include/offer/plugins/block_info/*.hpp")

add_library( offer_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( offer_block_info offer_app offer_chain offer_protocol fc )
target_include_directories( offer_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
