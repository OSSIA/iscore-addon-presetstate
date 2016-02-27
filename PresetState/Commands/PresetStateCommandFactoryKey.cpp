#include "PresetStateCommandFactoryKey.hpp"
#include <iscore/command/SerializableCommand.hpp>

const CommandParentFactoryKey& PresetState::CommandFactoryName() {
    static const CommandParentFactoryKey key{"PresetState"};
    return key;
}
