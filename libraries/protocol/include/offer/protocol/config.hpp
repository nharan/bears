/*
 * Copyright (c) 2016 Offerit, Inc., and contributors.
 */
#pragma once
#include <offer/protocol/hardfork.hpp>

// WARNING!
// Every symbol defined here needs to be handled appropriately in get_config.cpp
// This is checked by get_config_check.sh called from Dockerfile

#ifdef IS_TEST_NET
#define OFFER_BLOCKCHAIN_VERSION              ( version(0, 21, 0) )

#define OFFER_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define OFFER_INIT_PUBLIC_KEY_STR             (std::string( offer::protocol::public_key_type(OFFER_INIT_PRIVATE_KEY.get_public_key()) ))
#define OFFER_CHAIN_ID (fc::sha256::hash("testnet"))
#define OFFER_ADDRESS_PREFIX                  "TST"

#define OFFER_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define OFFER_MINING_TIME                     (fc::time_point_sec(1451606400))
#define OFFER_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define OFFER_CASHOUT_WINDOW_SECONDS_PRE_HF12 (OFFER_CASHOUT_WINDOW_SECONDS)
#define OFFER_CASHOUT_WINDOW_SECONDS_PRE_HF17 (OFFER_CASHOUT_WINDOW_SECONDS)
#define OFFER_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define OFFER_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define OFFER_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define OFFER_UPVOTE_LOCKOUT_SECONDS          (60*5)    /// 5 minutes
#define OFFER_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define OFFER_MIN_ACCOUNT_CREATION_FEE          0
#define OFFER_MAX_ACCOUNT_CREATION_FEE          int64_t(1000000000)

#define OFFER_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define OFFER_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define OFFER_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define OFFER_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#define OFFER_INIT_SUPPLY                     (int64_t( 250 ) * int64_t( 1000000 ) * int64_t( 1000 ))

/// Allows to limit number of total produced blocks.
#define TESTNET_BLOCK_LIMIT                   (3000000)

#else // IS LIVE OFFER NETWORK

#define OFFER_BLOCKCHAIN_VERSION              ( version(0, 20, 5) )

#define OFFER_INIT_PUBLIC_KEY_STR             "SHR7YDq7bh9EG3oufCAPRjf1ZESqCqjdjj55Xp2QXDTnYndVqxBom"
#define OFFER_CHAIN_ID (fc::sha256::hash("I love Pakistan"))
#define OFFER_ADDRESS_PREFIX                  "SHR"

#define OFFER_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define OFFER_MINING_TIME                     (fc::time_point_sec(1458838800))
#define OFFER_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24*5)    /// 5 days
#define OFFER_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*24*7)    /// 7 Days 
#define OFFER_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define OFFER_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define OFFER_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define OFFER_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define OFFER_UPVOTE_LOCKOUT_SECONDS          (60*60*12)    /// 12 hours
#define OFFER_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define OFFER_MIN_ACCOUNT_CREATION_FEE           1
#define OFFER_MAX_ACCOUNT_CREATION_FEE           int64_t(1000000000)

#define OFFER_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define OFFER_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define OFFER_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define OFFER_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 0

#define OFFER_INIT_SUPPLY                     (int64_t( 900 ) * int64_t( 1000000 ) * int64_t( 1000 ))

#endif

#define COINS_SYMBOL  (offer::protocol::asset_symbol_type::from_asset_num( OFFER_ASSET_NUM_COINS ) )
#define OFFER_SYMBOL  (offer::protocol::asset_symbol_type::from_asset_num( OFFER_ASSET_NUM_OFFER ) )
#define BSD_SYMBOL    (offer::protocol::asset_symbol_type::from_asset_num( OFFER_ASSET_NUM_BSD ) )

#define OFFER_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( OFFER_BLOCKCHAIN_VERSION ) )

#define OFFER_BLOCK_INTERVAL                  3
#define OFFER_BLOCKS_PER_YEAR                 (365*24*60*60/OFFER_BLOCK_INTERVAL)
#define OFFER_BLOCKS_PER_DAY                  (24*60*60/OFFER_BLOCK_INTERVAL)
#define OFFER_START_COINING_BLOCK             (OFFER_BLOCKS_PER_DAY * 7)
#define OFFER_INFLATION_NUMBER                0

#define OFFER_START_MINER_VOTING_BLOCK        (OFFER_BLOCKS_PER_YEAR * 5)

#define OFFER_INIT_MINER_NAME                 "offerhare"
#define OFFER_NUM_INIT_MINERS                 1
#define OFFER_INIT_TIME                       (fc::time_point_sec());

#define OFFER_MAX_WITNESSES                   21

#define OFFER_MAX_VOTED_WITNESSES_HF0         19
#define OFFER_MAX_MINER_WITNESSES_HF0         1
#define OFFER_MAX_RUNNER_WITNESSES_HF0        1

#define OFFER_MAX_VOTED_WITNESSES_HF17        20
#define OFFER_MAX_MINER_WITNESSES_HF17        0
#define OFFER_MAX_RUNNER_WITNESSES_HF17       1

#define OFFER_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define OFFER_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define OFFER_MAX_MEMO_SIZE                   2048
#define OFFER_MAX_PROXY_RECURSION_DEPTH       4
#define OFFER_COINING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define OFFER_COINING_WITHDRAW_INTERVALS      13
#define OFFER_COINING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define OFFER_MAX_WITHDRAW_ROUTES             10
#define OFFER_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define OFFER_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define OFFER_VOTING_MANA_REGENERATION_SECONDS (5*60*60*24) // 5 day
#define OFFER_MAX_VOTE_CHANGES                5
#define OFFER_REVERSE_AUCTION_WINDOW_SECONDS_HF6 (60*30) /// 30 minutes
#define OFFER_REVERSE_AUCTION_WINDOW_SECONDS_HF20 (60*15) /// 15 minutes
#define OFFER_MIN_VOTE_INTERVAL_SEC           3
#define OFFER_VOTE_DUST_THRESHOLD             (2500)

#define OFFER_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define OFFER_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define OFFER_MIN_REPLY_INTERVAL_HF20         (fc::seconds(3)) // 3 seconds
#define OFFER_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define OFFER_POST_WEIGHT_CONSTANT            (uint64_t(4*OFFER_100_PERCENT) * (4*OFFER_100_PERCENT))// (4*OFFER_100_PERCENT) -> 2 posts per 1 days, average 1 every 12 hours

#define OFFER_MAX_ACCOUNT_WITNESS_VOTES       30

#define OFFER_100_PERCENT                     10000
#define OFFER_1_PERCENT                       (OFFER_100_PERCENT/100)
#define OFFER_DEFAULT_BSD_INTEREST_RATE       (10*OFFER_1_PERCENT) ///< 10% APR

#define OFFER_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define OFFER_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define OFFER_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define OFFER_CONTENT_REWARD_PERCENT          (75*OFFER_1_PERCENT) //75% of inflation, 7.125% inflation
#define OFFER_COINING_FUND_PERCENT            (15*OFFER_1_PERCENT) //15% of inflation, 1.425% inflation

#define OFFER_MINER_PAY_PERCENT               (OFFER_1_PERCENT) // 1%
#define OFFER_MAX_RATION_DECAY_RATE           (1000000)

#define OFFER_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define OFFER_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define OFFER_MAX_COMMENT_DEPTH_PRE_HF17      6
#define OFFER_MAX_COMMENT_DEPTH               0xffff // 64k
#define OFFER_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define OFFER_MAX_RESERVE_RATIO               (20000)

#define OFFER_CREATE_ACCOUNT_WITH_OFFER_MODIFIER 1
#define OFFER_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define OFFER_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define OFFER_MINING_REWARD                   asset( 100, OFFER_SYMBOL )
#define OFFER_EQUIHASH_N                      140
#define OFFER_EQUIHASH_K                      6

#define OFFER_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define OFFER_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define OFFER_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define OFFER_LIQUIDITY_REWARD_BLOCKS         (OFFER_LIQUIDITY_REWARD_PERIOD_SEC/OFFER_BLOCK_INTERVAL)
#define OFFER_MIN_LIQUIDITY_REWARD            (asset( 1000*OFFER_LIQUIDITY_REWARD_BLOCKS, OFFER_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define OFFER_MIN_CONTENT_REWARD              OFFER_MINING_REWARD
#define OFFER_MIN_CURATE_REWARD               OFFER_MINING_REWARD
#define OFFER_MIN_PRODUCER_REWARD             OFFER_MINING_REWARD
#define OFFER_MIN_POW_REWARD                  OFFER_MINING_REWARD

#define OFFER_ACTIVE_CHALLENGE_FEE            asset( 2000, OFFER_SYMBOL )
#define OFFER_OWNER_CHALLENGE_FEE             asset( 30000, OFFER_SYMBOL )
#define OFFER_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define OFFER_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define OFFER_POST_REWARD_FUND_NAME           ("post")
#define OFFER_COMMENT_REWARD_FUND_NAME        ("comment")
#define OFFER_RECENT_RSHARES_DECAY_TIME_HF17    (fc::days(30))
#define OFFER_RECENT_RSHARES_DECAY_TIME_HF19    (fc::days(15))
#define OFFER_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**OFFER_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for coining
#define OFFER_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that OFFER_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define OFFER_APR_PERCENT_SHIFT_PER_BLOCK             87

#define OFFER_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define OFFER_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**OFFER_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define OFFER_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that OFFER_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define OFFER_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x coining rewards*
#define OFFER_CURATE_APR_PERCENT              3875
#define OFFER_CONTENT_APR_PERCENT             3875
#define OFFER_LIQUIDITY_APR_PERCENT            750
#define OFFER_PRODUCER_APR_PERCENT             750
#define OFFER_POW_APR_PERCENT                  750

#define OFFER_MIN_PAYOUT_BSD                  (asset(20,BSD_SYMBOL))

#define OFFER_BSD_STOP_PERCENT_HF14           (5*OFFER_1_PERCENT ) // Stop printing BSD at 5% Market Cap
#define OFFER_BSD_STOP_PERCENT_HF20           (10*OFFER_1_PERCENT ) // Stop printing BSD at 10% Market Cap
#define OFFER_BSD_START_PERCENT_HF14          (2*OFFER_1_PERCENT) // Start reducing printing of BSD at 2% Market Cap
#define OFFER_BSD_START_PERCENT_HF20          (9*OFFER_1_PERCENT) // Start reducing printing of BSD at 9% Market Cap

#define OFFER_MIN_ACCOUNT_NAME_LENGTH          3
#define OFFER_MAX_ACCOUNT_NAME_LENGTH         16

#define OFFER_MIN_PERMLINK_LENGTH             0
#define OFFER_MAX_PERMLINK_LENGTH             256
#define OFFER_MAX_WITNESS_URL_LENGTH          2048

#define OFFER_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define OFFER_MAX_SATOSHIS                    int64_t(4611686018427387903ll)
#define OFFER_MAX_SIG_CHECK_DEPTH             2
#define OFFER_MAX_SIG_CHECK_ACCOUNTS          125

#define OFFER_MIN_TRANSACTION_SIZE_LIMIT      1024
#define OFFER_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define OFFER_BSD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define OFFER_MAX_TRANSACTION_SIZE            (1024*64)
#define OFFER_MIN_BLOCK_SIZE_LIMIT            (OFFER_MAX_TRANSACTION_SIZE)
#define OFFER_MAX_BLOCK_SIZE                  (OFFER_MAX_TRANSACTION_SIZE*OFFER_BLOCK_INTERVAL*2000)
#define OFFER_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define OFFER_MIN_BLOCK_SIZE                  115
#define OFFER_BLOCKS_PER_HOUR                 (60*60/OFFER_BLOCK_INTERVAL)
#define OFFER_FEED_INTERVAL_BLOCKS            (OFFER_BLOCKS_PER_HOUR/12) // Update every 100 blocks 
#define OFFER_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define OFFER_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define OFFER_MAX_FEED_AGE_SECONDS            (60*60*1) // 1 hour
#define OFFER_MIN_FEEDS                       (OFFER_MAX_WITNESSES/7) /// 3 Witnesses to publish feed..  protects the network from conversions before price has been established
#define OFFER_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define OFFER_CONVERSION_DELAY                (fc::hours(OFFER_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define OFFER_MIN_UNDO_HISTORY                10
#define OFFER_MAX_UNDO_HISTORY                10000

#define OFFER_MIN_TRANSACTION_EXPIRATION_LIMIT (OFFER_BLOCK_INTERVAL * 5) // 5 transactions per block
#define OFFER_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define OFFER_BLOCKCHAIN_PRECISION_DIGITS     3
#define OFFER_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define OFFER_MAX_AUTHORITY_MEMBERSHIP        40
#define OFFER_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define OFFER_MAX_URL_LENGTH                  127

#define OFFER_IRREVERSIBLE_THRESHOLD          (75 * OFFER_1_PERCENT)

#define OFFER_VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define OFFER_VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

#define OFFER_INITIAL_VOTE_POWER_RATE (20)
#define OFFER_REDUCED_VOTE_POWER_RATE (20)

#define OFFER_MAX_LIMIT_ORDER_EXPIRATION     (60*60*24*28) // 28 days
#define OFFER_DELEGATION_RETURN_PERIOD_HF0   (OFFER_CASHOUT_WINDOW_SECONDS)
#define OFFER_DELEGATION_RETURN_PERIOD_HF20  (OFFER_VOTING_MANA_REGENERATION_SECONDS)

#define OFFER_RD_MIN_DECAY_BITS               6
#define OFFER_RD_MAX_DECAY_BITS              32
#define OFFER_RD_DECAY_DENOM_SHIFT           36
#define OFFER_RD_MAX_POOL_BITS               64
#define OFFER_RD_MAX_BUDGET_1                ((uint64_t(1) << (OFFER_RD_MAX_POOL_BITS + OFFER_RD_MIN_DECAY_BITS - OFFER_RD_DECAY_DENOM_SHIFT))-1)
#define OFFER_RD_MAX_BUDGET_2                ((uint64_t(1) << (64-OFFER_RD_DECAY_DENOM_SHIFT))-1)
#define OFFER_RD_MAX_BUDGET_3                (uint64_t( std::numeric_limits<int32_t>::max() ))
#define OFFER_RD_MAX_BUDGET                  (int32_t( std::min( { OFFER_RD_MAX_BUDGET_1, OFFER_RD_MAX_BUDGET_2, OFFER_RD_MAX_BUDGET_3 } )) )
#define OFFER_RD_MIN_DECAY                   (uint32_t(1) << OFFER_RD_MIN_DECAY_BITS)
#define OFFER_RD_MIN_BUDGET                  1
#define OFFER_RD_MAX_DECAY                   (uint32_t(0xFFFFFFFF))

#define OFFER_ACCOUNT_SUBSIDY_PRECISION      (OFFER_100_PERCENT)

// We want the global subsidy to run out first in normal (Poisson)
// conditions, so we boost the per-witness subsidy a little.
#define OFFER_WITNESS_SUBSIDY_BUDGET_PERCENT (125 * OFFER_1_PERCENT)

// Since witness decay only procs once per round, multiplying the decay
// constant by the number of witnesses means the per-witness pools have
// the same effective decay rate in real-time terms.
#define OFFER_WITNESS_SUBSIDY_DECAY_PERCENT  (OFFER_MAX_WITNESSES * OFFER_100_PERCENT)

// 347321 corresponds to a 5-day halflife
#define OFFER_DEFAULT_ACCOUNT_SUBSIDY_DECAY  (347321)
// Default rate is 0.5 accounts per block
#define OFFER_DEFAULT_ACCOUNT_SUBSIDY_BUDGET (797)
#define OFFER_DECAY_BACKSTOP_PERCENT         (90 * OFFER_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define OFFER_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define OFFER_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define OFFER_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define OFFER_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define OFFER_ROOT_POST_PARENT                (account_name_type())
///@}

#ifdef OFFER_ENABLE_SMT

#define SMT_MAX_VOTABLE_ASSETS 2
#define SMT_COINING_WITHDRAW_INTERVAL_SECONDS   (60*60*24*7) /// 1 week per interval
#define SMT_UPVOTE_LOCKOUT                      (60*60*12)  /// 12 hours

#endif /// OFFER_ENABLE_SMT

