file(GLOB HEADERS "include/offer/delayed_node/*.hpp")

add_library( offer_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( offer_delayed_node offer_chain offer_protocol offer_app )
target_include_directories( offer_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   offer_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
