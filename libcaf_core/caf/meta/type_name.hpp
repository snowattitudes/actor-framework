/******************************************************************************
 *                       ____    _    _____                                   *
 *                      / ___|  / \  |  ___|    C++                           *
 *                     | |     / _ \ | |_       Actor                         *
 *                     | |___ / ___ \|  _|      Framework                     *
 *                      \____/_/   \_|_|                                      *
 *                                                                            *
 * Copyright (C) 2011 - 2016                                                  *
 * Dominik Charousset <dominik.charousset (at) haw-hamburg.de>                *
 *                                                                            *
 * Distributed under the terms and conditions of the BSD 3-Clause License or  *
 * (at your option) under the terms and conditions of the Boost Software      *
 * License 1.0. See accompanying files LICENSE and LICENSE_ALTERNATIVE.       *
 *                                                                            *
 * If you did not receive a copy of the license files, see                    *
 * http://opensource.org/licenses/BSD-3-Clause and                            *
 * http://www.boost.org/LICENSE_1_0.txt.                                      *
 ******************************************************************************/

#ifndef CAF_META_TYPE_NAME_HPP
#define CAF_META_TYPE_NAME_HPP

#include "caf/meta/annotation.hpp"

namespace caf {
namespace meta {

struct type_name_t : annotation {
  constexpr type_name_t(const char* cstr) : value(cstr) {
    // nop
  }

  const char* value;
};

/// Returns a type name annotation.
type_name_t constexpr type_name(const char* cstr) {
  return {cstr};
}
} // namespace meta
} // namespace caf

#endif // CAF_META_TYPE_NAME_HPP
