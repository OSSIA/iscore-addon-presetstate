#include "PresetStateCommandFactoryKey.hpp"
#include <iscore/command/Command.hpp>

const CommandGroupKey& PresetState::CommandFactoryName() {
    static const CommandGroupKey key{"PresetState"};
    return key;
}
