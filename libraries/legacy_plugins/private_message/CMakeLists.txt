file(GLOB HEADERS "include/offer/private_message/*.hpp")

add_library( offer_private_message
             private_message_plugin.cpp
           )

target_link_libraries( offer_private_message offer_chain offer_protocol offer_app )
target_include_directories( offer_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   offer_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
