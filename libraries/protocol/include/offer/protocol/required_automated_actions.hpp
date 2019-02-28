#pragma once

#include <offer/protocol/offer_required_actions.hpp>

#include <offer/protocol/operation_util.hpp>

namespace offer { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            required_action
         > required_automated_action;

} } // offer::protocol

OFFER_DECLARE_OPERATION_TYPE( offer::protocol::required_automated_action );
FC_REFLECT_TYPENAME( offer::protocol::required_automated_action );
