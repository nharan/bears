#pragma once

#include <offer/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace offer { namespace app {
   struct api_context;
} }

namespace offer { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const offer::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // offer::account_statistics

FC_API( offer::account_statistics::account_statistics_api, )