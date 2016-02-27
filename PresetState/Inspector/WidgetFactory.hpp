#pragma once
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <PresetState/Metadata.hpp>

namespace PresetState
{
class InspectorFactory final :
        public Process::StateProcessInspectorWidgetDelegateFactory
{
        ISCORE_CONCRETE_FACTORY_DECL("af0e6253-9754-4b49-8ecb-f43b9d947fb8")
    public:
        InspectorFactory();
        virtual ~InspectorFactory();

    private:
        Process::StateProcessInspectorWidgetDelegate* make(
                const Process::StateProcess&,
                const iscore::DocumentContext&,
                QWidget* parent) const override;
        bool matches(const Process::StateProcess&) const override;
};
}
