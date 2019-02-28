#include <stdint.h>
#include <offer/utilities/git_revision.hpp>

#define OFFER_GIT_REVISION_SHA "cf0174e3ba2f62cdfe9fad359d5c5653e7473fc9"
#define OFFER_GIT_REVISION_UNIX_TIMESTAMP 1545723750
#define OFFER_GIT_REVISION_DESCRIPTION "v0.20.5-51-gcf0174e"

namespace offer { namespace utilities {

const char* const git_revision_sha = OFFER_GIT_REVISION_SHA;
const uint32_t git_revision_unix_timestamp = OFFER_GIT_REVISION_UNIX_TIMESTAMP;
const char* const git_revision_description = OFFER_GIT_REVISION_DESCRIPTION;

} } // end namespace offer::utilities
