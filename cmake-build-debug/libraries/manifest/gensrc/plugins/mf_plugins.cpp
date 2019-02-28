#include <appbase/application.hpp>
#include <boost/preprocessor/seq/for_each.hpp>

#include <offer/manifest/plugins.hpp>


#include <offer/plugins/tags/tags_plugin.hpp>

#include <offer/plugins/webserver/webserver_plugin.hpp>

#include <offer/plugins/statsd/statsd_plugin.hpp>

#include <offer/plugins/account_history_rocksdb/account_history_rocksdb_plugin.hpp>

#include <offer/plugins/debug_node/debug_node_plugin.hpp>

#include <offer/plugins/account_by_key/account_by_key_plugin.hpp>

#include <offer/plugins/stats_export/stats_export_plugin.hpp>

#include <offer/plugins/reputation/reputation_plugin.hpp>

#include <offer/plugins/market_history/market_history_plugin.hpp>

#include <offer/plugins/rc/rc_plugin.hpp>

#include <offer/plugins/account_history/account_history_plugin.hpp>

#include <offer/plugins/follow/follow_plugin.hpp>

#include <offer/plugins/witness/witness_plugin.hpp>

#include <offer/plugins/smt_test/smt_test_plugin.hpp>

#include <offer/plugins/block_data_export/block_data_export_plugin.hpp>

#include <offer/plugins/p2p/p2p_plugin.hpp>

#include <offer/plugins/chain/chain_plugin.hpp>

#include <offer/plugins/account_history_api/account_history_api_plugin.hpp>

#include <offer/plugins/account_by_key_api/account_by_key_api_plugin.hpp>

#include <offer/plugins/condenser_api/condenser_api_plugin.hpp>

#include <offer/plugins/follow_api/follow_api_plugin.hpp>

#include <offer/plugins/debug_node_api/debug_node_api_plugin.hpp>

#include <offer/plugins/witness_api/witness_api_plugin.hpp>

#include <offer/plugins/market_history_api/market_history_api_plugin.hpp>

#include <offer/plugins/chain_api/chain_api_plugin.hpp>

#include <offer/plugins/tags_api/tags_api_plugin.hpp>

#include <offer/plugins/reputation_api/reputation_api_plugin.hpp>

#include <offer/plugins/database_api/database_api_plugin.hpp>

#include <offer/plugins/rc_api/rc_api_plugin.hpp>

#include <offer/plugins/block_api/block_api_plugin.hpp>

#include <offer/plugins/network_broadcast_api/network_broadcast_api_plugin.hpp>

#include <offer/plugins/block_log_info/block_log_info_plugin.hpp>


namespace offer { namespace plugins {

void register_plugins()
{
   
   appbase::app().register_plugin< offer::plugins::tags::tags_plugin >();
   
   appbase::app().register_plugin< offer::plugins::webserver::webserver_plugin >();
   
   appbase::app().register_plugin< offer::plugins::statsd::statsd_plugin >();
   
   appbase::app().register_plugin< offer::plugins::account_history_rocksdb::account_history_rocksdb_plugin >();
   
   appbase::app().register_plugin< offer::plugins::debug_node::debug_node_plugin >();
   
   appbase::app().register_plugin< offer::plugins::account_by_key::account_by_key_plugin >();
   
   appbase::app().register_plugin< offer::plugins::stats_export::stats_export_plugin >();
   
   appbase::app().register_plugin< offer::plugins::reputation::reputation_plugin >();
   
   appbase::app().register_plugin< offer::plugins::market_history::market_history_plugin >();
   
   appbase::app().register_plugin< offer::plugins::rc::rc_plugin >();
   
   appbase::app().register_plugin< offer::plugins::account_history::account_history_plugin >();
   
   appbase::app().register_plugin< offer::plugins::follow::follow_plugin >();
   
   appbase::app().register_plugin< offer::plugins::witness::witness_plugin >();
   
   appbase::app().register_plugin< offer::plugins::smt_test::smt_test_plugin >();
   
   appbase::app().register_plugin< offer::plugins::block_data_export::block_data_export_plugin >();
   
   appbase::app().register_plugin< offer::plugins::p2p::p2p_plugin >();
   
   appbase::app().register_plugin< offer::plugins::chain::chain_plugin >();
   
   appbase::app().register_plugin< offer::plugins::account_history::account_history_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::account_by_key::account_by_key_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::condenser_api::condenser_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::follow::follow_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::debug_node::debug_node_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::witness::witness_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::market_history::market_history_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::chain::chain_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::tags::tags_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::reputation::reputation_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::database_api::database_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::rc::rc_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::block_api::block_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::network_broadcast_api::network_broadcast_api_plugin >();
   
   appbase::app().register_plugin< offer::plugins::block_log_info::block_log_info_plugin >();
   
}

} }