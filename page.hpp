#ifndef PAGE_HPP_INCLUDED
#define PAGE_HPP_INCLUDED

#include "components/component.hpp"
#include "SimpleUtil/value_ptr/value_ptr.hpp"

#include <vector>
#include <memory>
#include <iosfwd>

namespace WikiMarkup
{
    class Page
    {
    public:
        Page() = default;
        ~Page() = default;

        template <typename T>
        void appendComponent(T const&& comp) {
            components_.emplace_back (new T(std::move(comp)));
        }

        void clear();

        void dumpComponentNames(std::ostream& stream);

    private:
        std::vector <sutil::value_ptr <Components::IComponent>> components_;
    };
}

#endif // PAGE_HPP_INCLUDED
