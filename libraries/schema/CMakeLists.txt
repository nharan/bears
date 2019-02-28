file(GLOB HEADERS "include/offer/schema/*.hpp")
add_library( offer_schema schema.cpp ${HEADERS} )
target_link_libraries( offer_schema fc )
target_include_directories( offer_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   offer_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/offer/schema" )
