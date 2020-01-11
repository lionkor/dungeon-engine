#include "acutest/include/acutest.h"
#include "../Core/GUID.h"

class GUIDTestObject : public GUID
{
};

void guid(void) {
    GUID g1;
    GUID g2;

    // not equals operator
    TEST_CHECK(g1 != g2);

    // GUID::int_guid
    TEST_CHECK(g1.int_guid() != g2.int_guid());

    //
    TEST_CHECK(g1.guid() == g1);

    GUIDTestObject one;
    GUIDTestObject other;
    TEST_CHECK(obj.guid() !=
}

void sanity_checks(void) {
    TEST_CHECK(sizeof(int) == 4);
    TEST_CHECK(sizeof(long) == 8);
    TEST_CHECK(sizeof(float) == 4);
    TEST_CHECK(sizeof(double) == 8);
    TEST_CHECK(sizeof(char) == 1);
}


TEST_LIST
    = {
          { "sanity checks", sanity_checks },
          { "class GUID", guid },

          // END
          { NULL, NULL }
      };
