file(GLOB HEADERS "include/offer/plugins/auth_util/*.hpp")

add_library( offer_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( offer_auth_util offer_app offer_chain offer_protocol fc )
target_include_directories( offer_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
