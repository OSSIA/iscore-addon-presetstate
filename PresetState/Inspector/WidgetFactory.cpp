#include <Inspector/InspectorWidgetFactoryInterface.hpp>
#include "WidgetFactory.hpp"
#include "Widget.hpp"
#include <PresetState/Model.hpp>

namespace PresetState
{

InspectorFactory::InspectorFactory()
{

}

InspectorFactory::~InspectorFactory()
{

}

Process::StateProcessInspectorWidgetDelegate* InspectorFactory::make(
        const Process::StateProcess& process,
        const iscore::DocumentContext& doc,
        QWidget* parent) const
{
    return new InspectorWidget{
        static_cast<const PresetState::Model&>(process),
                doc,
                parent};
}

bool InspectorFactory::matches(const Process::StateProcess& process) const
{
    return dynamic_cast<const PresetState::Model*>(&process);
}

}
