#pragma once

#include <offer/protocol/asset.hpp>

namespace offer { namespace chain { namespace util {

using offer::protocol::asset;
using offer::protocol::price;

inline asset to_bsd( const price& p, const asset& offer )
{
   FC_ASSERT( offer.symbol == OFFER_SYMBOL );
   if( p.is_null() )
      return asset( 0, BSD_SYMBOL );
   return offer * p;
}

inline asset to_offer( const price& p, const asset& bsd )
{
   FC_ASSERT( bsd.symbol == BSD_SYMBOL );
   if( p.is_null() )
      return asset( 0, OFFER_SYMBOL );
   return bsd * p;
}

} } }
