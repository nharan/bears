#pragma once

#include <vector>

namespace offer{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed.offerit.org:3331"
};
#endif

} } } // offer::plugins::p2p
