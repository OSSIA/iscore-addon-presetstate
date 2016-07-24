#include "StateComponent.hpp"
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <OSSIA/iscore2OSSIA.hpp>
#include <PresetState/Model.hpp>
#include <Editor/Message.h>
#include <OSSIA/iscore2OSSIA.hpp>


namespace PresetState
{
namespace Executor
{
static void convert(
        const Preset& p,
        OSSIA::State& state,
        const Device::DeviceList& lst)
{
    for(auto& message : p)
    {
        state.add(iscore::convert::message(message, lst));
    }
}

//// Component ////
StateProcessComponent::StateProcessComponent(
        RecreateOnPlay::StateElement& parentConstraint,
        Model& element,
        const RecreateOnPlay::Context& ctx,
        const Id<iscore::Component>& id,
        QObject* parent):
    RecreateOnPlay::StateProcessComponent_T<PresetState::Model>{
        parentConstraint, element, ctx, id, "PresetStateComponent", parent}
{
    OSSIA::State state;

    // We just add messages
    convert(element.preset(), state, ctx.devices.list());

    m_ossia_state = std::move(state);
}

OSSIA::StateElement StateProcessComponent::make(
        Process::StateProcess &proc,
        const RecreateOnPlay::Context &ctx)
{
    OSSIA::State state;
    convert(static_cast<Model&>(proc).preset(), state, ctx.devices.list());
    return state;
}

}
}
