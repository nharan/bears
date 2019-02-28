#pragma once

#include <offer/protocol/block.hpp>

namespace offer { namespace chain {

struct transaction_notification
{
   transaction_notification( const offer::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   offer::protocol::transaction_id_type          transaction_id;
   const offer::protocol::signed_transaction&    transaction;
};

} }
