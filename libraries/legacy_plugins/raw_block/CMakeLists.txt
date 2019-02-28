file(GLOB HEADERS "include/offer/plugins/raw_block/*.hpp")

add_library( offer_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( offer_raw_block offer_app offer_chain offer_protocol fc )
target_include_directories( offer_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
