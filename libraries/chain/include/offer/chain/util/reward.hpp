#pragma once

#include <offer/chain/util/asset.hpp>
#include <offer/chain/offer_objects.hpp>

#include <offer/protocol/asset.hpp>
#include <offer/protocol/config.hpp>
#include <offer/protocol/types.hpp>
#include <offer/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace offer { namespace chain { namespace util {

using offer::protocol::asset;
using offer::protocol::price;
using offer::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_bsd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_offer;
   price      current_offer_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = OFFER_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return OFFER_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = OFFER_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t offer_payout )
{
   return to_bsd( p, asset( offer_payout, OFFER_SYMBOL ) ) < OFFER_MIN_PAYOUT_BSD;
}

} } } // offer::chain::util

FC_REFLECT( offer::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_bsd)
   (total_reward_shares2)
   (total_reward_fund_offer)
   (current_offer_price)
   (reward_curve)
   (content_constant)
   )
