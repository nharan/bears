#pragma once
#include <offer/plugins/block_api/block_api_objects.hpp>

#include <offer/protocol/types.hpp>
#include <offer/protocol/transaction.hpp>
#include <offer/protocol/block_header.hpp>

#include <offer/plugins/json_rpc/utility.hpp>

namespace offer { namespace plugins { namespace block_api {

/* get_block_header */

struct get_block_header_args
{
   uint32_t block_num;
};

struct get_block_header_return
{
   optional< block_header > header;
};

/* get_block */
struct get_block_args
{
   uint32_t block_num;
};

struct get_block_return
{
   optional< api_signed_block_object > block;
};

} } } // offer::block_api

FC_REFLECT( offer::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( offer::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( offer::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( offer::plugins::block_api::get_block_return,
   (block) )

