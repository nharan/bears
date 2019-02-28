#pragma once
#include <offer/protocol/block_header.hpp>
#include <offer/protocol/transaction.hpp>

namespace offer { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // offer::protocol

FC_REFLECT_DERIVED( offer::protocol::signed_block, (offer::protocol::signed_block_header), (transactions) )
