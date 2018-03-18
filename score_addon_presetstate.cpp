#include "score_addon_presetstate.hpp"
#include <PresetState/Inspector/WidgetFactory.hpp>
#include <PresetState/Commands/PresetStateCommandFactoryKey.hpp>
#include <PresetState/Factory.hpp>
#include <PresetState/Executor/StateComponent.hpp>

#include <Inspector/InspectorWidgetFactoryInterface.hpp>
#include <Process/ProcessFactory.hpp>
#include <score/plugins/customfactory/StringFactoryKey.hpp>
#include <score/plugins/customfactory/FactoryFamily.hpp>
#include <score/plugins/customfactory/FactorySetup.hpp>

#include <unordered_map>
#include <score_addon_presetstate_commands_files.hpp>
score_addon_presetstate::score_addon_presetstate() :
    QObject {}
{
}

score_addon_presetstate::~score_addon_presetstate()
{

}

std::vector<std::unique_ptr<score::InterfaceBase>> score_addon_presetstate::factories(
        const score::ApplicationContext& ctx,
        const score::InterfaceKey& key) const
{
    return instantiate_factories<
            score::ApplicationContext,
        FW<Process::ProcessModelFactory,
             PresetState::Factory>,
        FW<Inspector::InspectorWidgetFactory,
             PresetState::Inspector::Factory>
        //, FW<Engine::Execution::ProcessComponentFactory, PresetState::Executor::ProcessComponentFactory>
    >(ctx, key);
}

std::pair<const CommandGroupKey, CommandGeneratorMap> score_addon_presetstate::make_commands()
{
    using namespace PresetState;
    std::pair<const CommandGroupKey, CommandGeneratorMap> cmds{
        PresetState::CommandFactoryName(),
                CommandGeneratorMap{}};

    using Types = TypeList<
#include <score_addon_presetstate_commands.hpp>
      >;
    for_each_type<Types>(score::commands::FactoryInserter{cmds.second});


    return cmds;
}

