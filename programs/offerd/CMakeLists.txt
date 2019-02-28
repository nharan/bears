add_executable( offerd main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling offerd with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( OFFER_STATIC_BUILD )
   target_link_libraries( offerd PRIVATE
      "-static-libstdc++ -static-libgcc"
      appbase
      offer_utilities
      offer_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( OFFER_STATIC_BUILD )
   target_link_libraries( offerd PRIVATE
      appbase
      offer_utilities
      offer_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( OFFER_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      offerd PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   offerd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
