#pragma once
#include <QString>
#include <memory>

#include <OSSIA/Executor/ProcessElement.hpp>
#include <OSSIA/Executor/ExecutorContext.hpp>
#include <OSSIA/Executor/StateProcessComponent.hpp>
#include <iscore/document/DocumentContext.hpp>
#include <iscore/document/DocumentInterface.hpp>
#include <PresetState/Preset.hpp>
#include <PresetState/Model.hpp>

namespace PresetState
{
namespace Executor
{
class StateProcessComponent final :
        public RecreateOnPlay::StateProcessComponent_T<PresetState::Model>
{
        COMPONENT_METADATA("b76014d1-d822-4323-a30a-946b26f41cf0")
    public:
        StateProcessComponent(
                RecreateOnPlay::StateElement& parentState,
                PresetState::Model& element,
                const RecreateOnPlay::Context& ctx,
                const Id<iscore::Component>& id,
                QObject* parent);

        static ossia::state_element make(
                Process::StateProcess& proc,
                const RecreateOnPlay::Context& ctxt);
};
using StateProcessComponentFactory = ::RecreateOnPlay::StateProcessComponentFactory_T<StateProcessComponent>;
}
}
