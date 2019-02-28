#pragma once

#include <fc/container/flat.hpp>
#include <offer/protocol/operations.hpp>
#include <offer/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace offer { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const offer::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const offer::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // offer::app
