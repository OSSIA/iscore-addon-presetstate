//#pragma once
//#include <QString>
//#include <memory>

//#include <Engine/Executor/ProcessComponent.hpp>
//#include <Engine/Executor/ExecutorContext.hpp>
//#include <Engine/Executor/StateProcessComponent.hpp>
//#include <score/document/DocumentContext.hpp>
//#include <score/document/DocumentInterface.hpp>
//#include <PresetState/Preset.hpp>
//#include <PresetState/Model.hpp>

//namespace PresetState
//{
//namespace Executor
//{
//class StateProcessComponent final :
//        public Engine::Execution::StateProcessComponent_T<PresetState::Model>
//{
//        COMPONENT_METADATA("b76014d1-d822-4323-a30a-946b26f41cf0")
//    public:
//        StateProcessComponent(
//                Engine::Execution::StateComponent& parentState,
//                PresetState::Model& element,
//                const Engine::Execution::Context& ctx,
//                const Id<score::Component>& id,
//                QObject* parent);

//        static ossia::state_element make(
//                Process::StateProcess& proc,
//                const Engine::Execution::Context& ctxt);
//};
//using StateProcessComponentFactory = ::Engine::Execution::StateProcessComponentFactory_T<StateProcessComponent>;
//}
//}
