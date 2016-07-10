#pragma once
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <PresetState/Metadata.hpp>

namespace PresetState
{
namespace Inspector
{
class Factory final :
        public Process::StateProcessInspectorWidgetDelegateFactory
{
        ISCORE_CONCRETE_FACTORY("577bc362-e279-488c-b0ac-5972851ea291")
    public:
        Factory();
        virtual ~Factory();

    private:
        Process::StateProcessInspectorWidgetDelegate* make(
                const Process::StateProcess&,
                const iscore::DocumentContext&,
                QWidget* parent) const override;
        bool matches(const Process::StateProcess&) const override;
};
}
}
