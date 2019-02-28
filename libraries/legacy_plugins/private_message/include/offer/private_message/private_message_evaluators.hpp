#pragma once

#include <offer/chain/evaluator.hpp>

#include <offer/private_message/private_message_operations.hpp>
#include <offer/private_message/private_message_plugin.hpp>

namespace offer { namespace private_message {

OFFER_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, offer::private_message::private_message_plugin_operation, private_message )

} }
