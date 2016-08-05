#include "StateComponent.hpp"
#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>
#include <OSSIA/iscore2OSSIA.hpp>
#include <PresetState/Model.hpp>
#include <ossia/editor/state/state_element.hpp>
#include <OSSIA/iscore2OSSIA.hpp>


namespace PresetState
{
namespace Executor
{
static void convert(
        const Preset& p,
        ossia::state& state,
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
    ossia::state state;

    // We just add messages
    convert(element.preset(), state, ctx.devices.list());

    m_ossia_state = std::move(state);
}

ossia::state_element StateProcessComponent::make(
        Process::StateProcess &proc,
        const RecreateOnPlay::Context &ctx)
{
    ossia::state state;
    convert(static_cast<Model&>(proc).preset(), state, ctx.devices.list());
    return state;
}

}
}
