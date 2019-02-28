#pragma once

#include <offer/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace offer { namespace protocol {
struct signed_transaction;
} } // offer::protocol

namespace offer { namespace plugins { namespace rc {

using offer::protocol::account_name_type;
using offer::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // offer::plugins::rc
