#pragma once
#include <cstdint>
#include <ostream>

namespace projectSystemC
{
    struct InputData
    {
        uint8_t firstStorage{};
        uint16_t operation{};
        uint8_t secondStorage{};

        friend std::ostream &operator<<(std::ostream &os, const InputData &inputData)
        {
            os << "First storage: " << inputData.firstStorage << std::endl;
            os << "Operation: " << inputData.operation << std::endl;
            os << "Second storage: " << inputData.secondStorage << std::endl;
            return os;
        }

        friend bool operator==(const InputData &lhs, const InputData &rhs)
        {
            return lhs.firstStorage == rhs.firstStorage && lhs.operation == rhs.operation && lhs.secondStorage == rhs.secondStorage;
        }
    };
} // namespace projectSystemC
