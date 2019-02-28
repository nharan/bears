#pragma once

#include <offer/protocol/asset.hpp>

namespace offer { namespace plugins { namespace condenser_api {

using offer::protocol::asset;
using offer::protocol::asset_symbol_type;
using offer::protocol::share_type;

struct legacy_asset
{
   public:
      legacy_asset() {}

      asset to_asset()const
      {
         return asset( amount, symbol );
      }

      operator asset()const { return to_asset(); }

      static legacy_asset from_asset( const asset& a )
      {
         legacy_asset leg;
         leg.amount = a.amount;
         leg.symbol = a.symbol;
         return leg;
      }

      string to_string()const;
      static legacy_asset from_string( const string& from );

      share_type                       amount;
      asset_symbol_type                symbol = OFFER_SYMBOL;
};

} } } // offer::plugins::condenser_api

namespace fc {

   inline void to_variant( const offer::plugins::condenser_api::legacy_asset& a, fc::variant& var )
   {
      var = a.to_string();
   }

   inline void from_variant( const fc::variant& var, offer::plugins::condenser_api::legacy_asset& a )
   {
      a = offer::plugins::condenser_api::legacy_asset::from_string( var.as_string() );
   }

} // fc

FC_REFLECT( offer::plugins::condenser_api::legacy_asset,
   (amount)
   (symbol)
   )
