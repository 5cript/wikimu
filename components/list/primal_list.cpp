#include "primal_list.hpp"

namespace WikiMarkup { namespace Components
{
//#####################################################################################################################
    PrimalList* PrimalList::clone() const
    {
        return new PrimalList(*this);
    }
//#####################################################################################################################
}
}
