/**
 *
 * Copyright 2018 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "net/grpc/gateway/runtime/tag.h"

#include <algorithm>

namespace grpc {
namespace gateway {

Tag::Tag(std::shared_ptr<void> instance, std::function<void(bool)> function)
    : instance_(std::move(instance)),
      function_(std::move(function)),
      result_(false) {}

Tag::~Tag() {}

void Tag::operator()() { function_(result_); }

}  // namespace gateway
}  // namespace grpc
