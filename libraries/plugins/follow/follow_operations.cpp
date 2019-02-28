#include <offer/plugins/follow/follow_operations.hpp>

#include <offer/protocol/operation_util_impl.hpp>

namespace offer { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //offer::plugins::follow

OFFER_DEFINE_OPERATION_TYPE( offer::plugins::follow::follow_plugin_operation )
