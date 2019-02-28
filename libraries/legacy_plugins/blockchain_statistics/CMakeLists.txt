file(GLOB HEADERS "include/offer/blockchain_statistics/*.hpp")

add_library( offer_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( offer_blockchain_statistics offer_chain offer_protocol offer_app )
target_include_directories( offer_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   offer_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)