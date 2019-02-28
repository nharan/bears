file(GLOB HEADERS "include/offer/account_statistics/*.hpp")

add_library( offer_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( offer_account_statistics offer_chain offer_protocol offer_app )
target_include_directories( offer_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   offer_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)