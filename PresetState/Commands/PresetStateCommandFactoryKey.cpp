#include "PresetStateCommandFactoryKey.hpp"
#include <iscore/command/Command.hpp>

const CommandParentFactoryKey& PresetState::CommandFactoryName() {
    static const CommandParentFactoryKey key{"PresetState"};
    return key;
}
