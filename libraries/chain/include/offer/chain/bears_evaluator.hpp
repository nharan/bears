#pragma once

#include <offer/protocol/offer_operations.hpp>

#include <offer/chain/evaluator.hpp>

namespace offer { namespace chain {

using namespace offer::protocol;

OFFER_DEFINE_EVALUATOR( account_create )
OFFER_DEFINE_EVALUATOR( account_create_with_delegation )
OFFER_DEFINE_EVALUATOR( account_update )
OFFER_DEFINE_EVALUATOR( transfer )
OFFER_DEFINE_EVALUATOR( transfer_to_coining )
OFFER_DEFINE_EVALUATOR( witness_update )
OFFER_DEFINE_EVALUATOR( account_witness_vote )
OFFER_DEFINE_EVALUATOR( account_witness_proxy )
OFFER_DEFINE_EVALUATOR( withdraw_coining )
OFFER_DEFINE_EVALUATOR( set_withdraw_coining_route )
OFFER_DEFINE_EVALUATOR( comment )
OFFER_DEFINE_EVALUATOR( comment_options )
OFFER_DEFINE_EVALUATOR( delete_comment )
OFFER_DEFINE_EVALUATOR( vote )
OFFER_DEFINE_EVALUATOR( custom )
OFFER_DEFINE_EVALUATOR( custom_json )
OFFER_DEFINE_EVALUATOR( custom_binary )
OFFER_DEFINE_EVALUATOR( pow )
OFFER_DEFINE_EVALUATOR( pow2 )
OFFER_DEFINE_EVALUATOR( feed_publish )
OFFER_DEFINE_EVALUATOR( convert )
OFFER_DEFINE_EVALUATOR( limit_order_create )
OFFER_DEFINE_EVALUATOR( limit_order_cancel )
OFFER_DEFINE_EVALUATOR( report_over_production )
OFFER_DEFINE_EVALUATOR( limit_order_create2 )
OFFER_DEFINE_EVALUATOR( escrow_transfer )
OFFER_DEFINE_EVALUATOR( escrow_approve )
OFFER_DEFINE_EVALUATOR( escrow_dispute )
OFFER_DEFINE_EVALUATOR( escrow_release )
OFFER_DEFINE_EVALUATOR( claim_account )
OFFER_DEFINE_EVALUATOR( create_claimed_account )
OFFER_DEFINE_EVALUATOR( request_account_recovery )
OFFER_DEFINE_EVALUATOR( recover_account )
OFFER_DEFINE_EVALUATOR( change_recovery_account )
OFFER_DEFINE_EVALUATOR( transfer_to_savings )
OFFER_DEFINE_EVALUATOR( transfer_from_savings )
OFFER_DEFINE_EVALUATOR( cancel_transfer_from_savings )
OFFER_DEFINE_EVALUATOR( decline_voting_rights )
OFFER_DEFINE_EVALUATOR( reset_account )
OFFER_DEFINE_EVALUATOR( set_reset_account )
OFFER_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef OFFER_ENABLE_SMT
OFFER_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
OFFER_DEFINE_EVALUATOR( delegate_coining_shares )
OFFER_DEFINE_EVALUATOR( witness_set_properties )
#ifdef OFFER_ENABLE_SMT
OFFER_DEFINE_EVALUATOR( smt_setup )
OFFER_DEFINE_EVALUATOR( smt_cap_reveal )
OFFER_DEFINE_EVALUATOR( smt_refund )
OFFER_DEFINE_EVALUATOR( smt_setup_emissions )
OFFER_DEFINE_EVALUATOR( smt_set_setup_parameters )
OFFER_DEFINE_EVALUATOR( smt_set_runtime_parameters )
OFFER_DEFINE_EVALUATOR( smt_create )
#endif

} } // offer::chain
