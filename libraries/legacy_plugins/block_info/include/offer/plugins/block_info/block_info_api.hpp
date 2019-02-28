
#pragma once

#include <fc/api.hpp>

#include <offer/plugins/block_info/block_info.hpp>

namespace offer { namespace app {
   struct api_context;
} }

namespace offer { namespace plugin { namespace block_info {

namespace detail {
class block_info_api_impl;
}

struct get_block_info_args
{
   uint32_t start_block_num = 0;
   uint32_t count           = 1000;
};

class block_info_api
{
   public:
      block_info_api( const offer::app::api_context& ctx );

      void on_api_startup();

      std::vector< block_info > get_block_info( get_block_info_args args );
      std::vector< block_with_info > get_blocks_with_info( get_block_info_args args );

   private:
      std::shared_ptr< detail::block_info_api_impl > my;
};

} } }

FC_REFLECT( offer::plugin::block_info::get_block_info_args,
   (start_block_num)
   (count)
   )

FC_API( offer::plugin::block_info::block_info_api,
   (get_block_info)
   (get_blocks_with_info)
   )
