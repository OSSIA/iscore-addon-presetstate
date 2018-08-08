#pragma once
#include <score/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>
#include <score/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <score/plugins/qt_interfaces/GUIApplicationPlugin_QtInterface.hpp>
#include <score/plugins/qt_interfaces/CommandFactory_QtInterface.hpp>
#include <QObject>
#include <utility>
#include <vector>

#include <score/application/ApplicationContext.hpp>
#include <score/command/CommandGeneratorMap.hpp>
#include <score/command/Command.hpp>
#include <score/plugins/customfactory/FactoryInterface.hpp>

class score_addon_presetstate final:
        public score::Plugin_QtInterface,
        public score::FactoryInterface_QtInterface,
        public score::CommandFactory_QtInterface
{
  SCORE_PLUGIN_METADATA(1, "8da162be-f8fb-4958-a49a-9e9571c5d969")

    public:
        score_addon_presetstate();
        virtual ~score_addon_presetstate();

    private:
        // Process & inspector
        std::vector<std::unique_ptr<score::InterfaceBase>> factories(
                const score::ApplicationContext& ctx,
                const score::InterfaceKey& factoryName) const override;

        // CommandFactory_QtInterface interface
        std::pair<const CommandGroupKey, CommandGeneratorMap> make_commands() override;
};
