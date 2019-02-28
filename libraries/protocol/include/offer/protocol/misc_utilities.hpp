#pragma once

namespace offer { namespace protocol {

// TODO:  Rename these curves to match naming in manual.md
enum curve_id
{
   quadratic,
   quadratic_curation,
   linear,
   square_root
};

} } // offer::utilities


FC_REFLECT_ENUM(
   offer::protocol::curve_id,
   (quadratic)
   (quadratic_curation)
   (linear)
   (square_root)
)
