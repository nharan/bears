
#pragma once

#include <offer/schema/abstract_schema.hpp>
#include <offer/schema/schema_impl.hpp>

#include <offer/protocol/asset_symbol.hpp>

namespace offer { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   OFFER_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< offer::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
