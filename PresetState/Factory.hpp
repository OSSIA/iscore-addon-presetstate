#pragma once
#include <Process/ProcessFactory.hpp>
#include <PresetState/Model.hpp>
#include <PresetState/Metadata.hpp>
#include <score/serialization/VisitorCommon.hpp>
#include <Process/GenericProcessFactory.hpp>
namespace PresetState
{
using Factory = Process::ProcessFactory_T<Model>;
}
