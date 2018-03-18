#include "PresetStateCommandFactoryKey.hpp"
#include <score/command/Command.hpp>

const CommandGroupKey& PresetState::CommandFactoryName() {
    static const CommandGroupKey key{"PresetState"};
    return key;
}
