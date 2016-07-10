#pragma once
#include <Process/ProcessFactory.hpp>
#include <PresetState/Model.hpp>
#include <PresetState/Metadata.hpp>
#include <iscore/serialization/VisitorCommon.hpp>
#include <Process/StateProcessFactory.hpp>
namespace PresetState
{
using Factory = Process::StateProcessFactory_T<Model>;
}
