#pragma once
#include <offer/plugins/chain/chain_plugin.hpp>
#include <offer/plugins/json_rpc/json_rpc_plugin.hpp>

#include <appbase/application.hpp>

namespace offer { namespace plugins { namespace database_api {

using namespace appbase;

#define OFFER_DATABASE_API_PLUGIN_NAME "database_api"

class database_api_plugin : public plugin< database_api_plugin >
{
   public:
      database_api_plugin();
      virtual ~database_api_plugin();

      APPBASE_PLUGIN_REQUIRES(
         (offer::plugins::json_rpc::json_rpc_plugin)
         (offer::plugins::chain::chain_plugin)
      )

      static const std::string& name() { static std::string name = OFFER_DATABASE_API_PLUGIN_NAME; return name; }

      virtual void set_program_options(
         options_description& cli,
         options_description& cfg ) override;
      virtual void plugin_initialize( const variables_map& options ) override;
      virtual void plugin_startup() override;
      virtual void plugin_shutdown() override;

      std::shared_ptr< class database_api > api;
};

} } } // offer::plugins::database_api
