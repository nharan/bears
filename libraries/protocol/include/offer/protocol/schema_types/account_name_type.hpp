
#pragma once

#include <offer/schema/abstract_schema.hpp>
#include <offer/schema/schema_impl.hpp>

#include <offer/protocol/types.hpp>

namespace offer { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   OFFER_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< offer::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< offer::protocol::account_name_type >
{
   static const char* name()
   {
      return "offer::protocol::account_name_type";
   }
};

}
