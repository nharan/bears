#pragma once
#include <offer/protocol/base.hpp>
#include <offer/protocol/block_header.hpp>
#include <offer/protocol/asset.hpp>
#include <offer/protocol/validation.hpp>
#include <offer/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace offer { namespace protocol {

   struct required_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }
   };

} } // offer::protocol

FC_REFLECT( offer::protocol::required_action, (account) )
