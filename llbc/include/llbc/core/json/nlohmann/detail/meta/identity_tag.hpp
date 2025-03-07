//     __ _____ _____ _____
//  __|  |   __|     |   | |  JSON for Modern C++
// |  |  |__   |  |  | | | |  version 3.11.3
// |_____|_____|_____|_|___|  https://github.com/nlohmann/json
//
// SPDX-FileCopyrightText: 2013-2023 Niels Lohmann <https://nlohmann.me>
// SPDX-License-Identifier: MIT

#pragma once

#include <llbc/core/json/nlohmann/detail/abi_macros.hpp>

LLBC_NLOHMANN_JSON_NAMESPACE_BEGIN
namespace detail
{

// dispatching helper struct
template <class T> struct identity_tag {};

}  // namespace detail
LLBC_NLOHMANN_JSON_NAMESPACE_END
