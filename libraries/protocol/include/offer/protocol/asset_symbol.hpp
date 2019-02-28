#pragma once

#include <fc/io/raw.hpp>
#include <offer/protocol/types_fwd.hpp>

#define OFFER_ASSET_SYMBOL_PRECISION_BITS    4
#define SMT_MAX_NAI                          99999999
#define SMT_MIN_NAI                          1
#define SMT_MIN_NON_RESERVED_NAI             10000000
#define OFFER_ASSET_SYMBOL_NAI_LENGTH        10
#define OFFER_ASSET_SYMBOL_NAI_STRING_LENGTH ( OFFER_ASSET_SYMBOL_NAI_LENGTH + 2 )

#define OFFER_PRECISION_BSD   (3)
#define OFFER_PRECISION_OFFER (3)
#define OFFER_PRECISION_COINS (6)

// One's place is used for check digit, which means NAI 0-9 all have NAI data of 0 which is invalid
// This space is safe to use because it would alwasys result in failure to convert from NAI
#define OFFER_NAI_BSD   (1)
#define OFFER_NAI_OFFER (2)
#define OFFER_NAI_COINS (3)

#define OFFER_ASSET_NUM_BSD \
  (((SMT_MAX_NAI + OFFER_NAI_BSD)   << OFFER_ASSET_SYMBOL_PRECISION_BITS) | OFFER_PRECISION_BSD)
#define OFFER_ASSET_NUM_OFFER \
  (((SMT_MAX_NAI + OFFER_NAI_OFFER) << OFFER_ASSET_SYMBOL_PRECISION_BITS) | OFFER_PRECISION_OFFER)
#define OFFER_ASSET_NUM_COINS \
  (((SMT_MAX_NAI + OFFER_NAI_COINS) << OFFER_ASSET_SYMBOL_PRECISION_BITS) | OFFER_PRECISION_COINS)

#ifdef IS_TEST_NET

#define COINS_SYMBOL_U64  (uint64_t('C') | (uint64_t('O') << 8) | (uint64_t('I') << 16) | (uint64_t('N') << 24) | (uint64_t('S') << 32))
#define OFFER_SYMBOL_U64  (uint64_t('T') | (uint64_t('E') << 8) | (uint64_t('S') << 16) | (uint64_t('T') << 24) | (uint64_t('S') << 32))
#define BSD_SYMBOL_U64    (uint64_t('T') | (uint64_t('B') << 8) | (uint64_t('D') << 16))

#else

#define COINS_SYMBOL_U64  (uint64_t('C') | (uint64_t('O') << 8) | (uint64_t('I') << 16) | (uint64_t('N') << 24) | (uint64_t('S') << 32))
#define OFFER_SYMBOL_U64  (uint64_t('B') | (uint64_t('E') << 8) | (uint64_t('A') << 16) | (uint64_t('R') << 24) | (uint64_t('S') << 32))
#define BSD_SYMBOL_U64    (uint64_t('B') | (uint64_t('S') << 8) | (uint64_t('D') << 16))

#endif

#define COINS_SYMBOL_SER  (uint64_t(6) | (COINS_SYMBOL_U64 << 8)) ///< COINS|COINS with 6 digits of precision
#define OFFER_SYMBOL_SER  (uint64_t(3) | (OFFER_SYMBOL_U64 << 8)) ///< OFFER|TESTS with 3 digits of precision
#define BSD_SYMBOL_SER    (uint64_t(3) |   (BSD_SYMBOL_U64 << 8)) ///< BSD|TBD with 3 digits of precision

#define OFFER_ASSET_MAX_DECIMALS 12

#define SMT_ASSET_NUM_PRECISION_MASK   0xF
#define SMT_ASSET_NUM_CONTROL_MASK     0x10
#define SMT_ASSET_NUM_COINING_MASK     0x20

namespace offer { namespace protocol {

class asset_symbol_type
{
   public:
      enum asset_symbol_space
      {
         legacy_space = 1,
         smt_nai_space = 2
      };

      asset_symbol_type() {}

      // buf must have space for OFFER_ASSET_SYMBOL_MAX_LENGTH+1
      static asset_symbol_type from_string( const std::string& str );
      static asset_symbol_type from_nai_string( const char* buf, uint8_t decimal_places );
      static asset_symbol_type from_asset_num( uint32_t asset_num )
      {   asset_symbol_type result;   result.asset_num = asset_num;   return result;   }
      static uint32_t asset_num_from_nai( uint32_t nai, uint8_t decimal_places );
      static asset_symbol_type from_nai( uint32_t nai, uint8_t decimal_places )
      {   return from_asset_num( asset_num_from_nai( nai, decimal_places ) );          }

      std::string to_string()const;

      void to_nai_string( char* buf )const;
      std::string to_nai_string()const
      {
         char buf[ OFFER_ASSET_SYMBOL_NAI_STRING_LENGTH ];
         to_nai_string( buf );
         return std::string( buf );
      }

      uint32_t to_nai()const;

      /**Returns true when symbol represents coining variant of the token,
       * false for liquid one.
       */
      bool is_coining() const;
      /**Returns coining symbol when called from liquid one
       * and liquid symbol when called from coining one.
       * Returns back the BSD symbol if represents BSD.
       */
      asset_symbol_type get_paired_symbol() const;
      /**Returns asset_num stripped of precision holding bits.
       * \warning checking that it's SMT symbol is caller responsibility.
       */
      uint32_t get_stripped_precision_smt_num() const
      { 
         return asset_num & ~( SMT_ASSET_NUM_PRECISION_MASK );
      }

      asset_symbol_space space()const;
      uint8_t decimals()const
      {  return uint8_t( asset_num & 0x0F );    }
      void validate()const;

      friend bool operator == ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num == b.asset_num);   }
      friend bool operator != ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num != b.asset_num);   }
      friend bool operator <  ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num <  b.asset_num);   }
      friend bool operator >  ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num >  b.asset_num);   }
      friend bool operator <= ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num <= b.asset_num);   }
      friend bool operator >= ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num >= b.asset_num);   }

      uint32_t asset_num = 0;
};

} } // offer::protocol

FC_REFLECT(offer::protocol::asset_symbol_type, (asset_num))

namespace fc { namespace raw {

// Legacy serialization of assets
// 0000pppp aaaaaaaa bbbbbbbb cccccccc dddddddd eeeeeeee ffffffff 00000000
// Symbol = abcdef
//
// NAI serialization of assets
// aaa1pppp bbbbbbbb cccccccc dddddddd
// NAI = (MSB to LSB) dddddddd cccccccc bbbbbbbb aaa
//
// NAI internal storage of legacy assets

template< typename Stream >
inline void pack( Stream& s, const offer::protocol::asset_symbol_type& sym )
{
   switch( sym.space() )
   {
      case offer::protocol::asset_symbol_type::legacy_space:
      {
         uint64_t ser = 0;
         switch( sym.asset_num )
         {
            case OFFER_ASSET_NUM_OFFER:
               ser = OFFER_SYMBOL_SER;
               break;
            case OFFER_ASSET_NUM_BSD:
               ser = BSD_SYMBOL_SER;
               break;
            case OFFER_ASSET_NUM_COINS:
               ser = COINS_SYMBOL_SER;
               break;
            default:
               FC_ASSERT( false, "Cannot serialize unknown asset symbol" );
         }
         pack( s, ser );
         break;
      }
      case offer::protocol::asset_symbol_type::smt_nai_space:
         pack( s, sym.asset_num );
         break;
      default:
         FC_ASSERT( false, "Cannot serialize unknown asset symbol" );
   }
}

template< typename Stream >
inline void unpack( Stream& s, offer::protocol::asset_symbol_type& sym )
{
   uint64_t ser = 0;
   s.read( (char*) &ser, 4 );

   switch( ser )
   {
      case OFFER_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == OFFER_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = OFFER_ASSET_NUM_OFFER;
         break;
      case BSD_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == BSD_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = OFFER_ASSET_NUM_BSD;
         break;
      case COINS_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == COINS_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = OFFER_ASSET_NUM_COINS;
         break;
      default:
         sym.asset_num = uint32_t( ser );
   }
   sym.validate();
}

} // fc::raw

inline void to_variant( const offer::protocol::asset_symbol_type& sym, fc::variant& var )
{
   try
   {
      std::vector< variant > v( 2 );
      v[0] = sym.decimals();
      v[1] = sym.to_nai_string();
   } FC_CAPTURE_AND_RETHROW()
}

inline void from_variant( const fc::variant& var, offer::protocol::asset_symbol_type& sym )
{
   try
   {
      auto v = var.as< std::vector< variant > >();
      FC_ASSERT( v.size() == 2, "Expected tuple of length 2." );

      sym = offer::protocol::asset_symbol_type::from_nai_string( v[1].as< std::string >().c_str(), v[0].as< uint8_t >() );
   } FC_CAPTURE_AND_RETHROW()
}

} // fc
