////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2016 ArangoDB GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Simon Grätzer
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGODB_PREGEL_ALGOS_SSSP_H
#define ARANGODB_PREGEL_ALGOS_SSSP_H 1

#include "Pregel/Algorithm.h"

namespace arangodb {
namespace pregel {
namespace algos {

/// PageRank
 struct PageRankAlgorithm : public Algorithm<float, float, float> {
 public:
  PageRankAlgorithm() : Algorithm("PageRank") {}

  std::shared_ptr<GraphFormat<float, float>> inputFormat() const override;
  std::shared_ptr<MessageFormat<float>> messageFormat() const override;
  std::shared_ptr<MessageCombiner<float>> messageCombiner() const override;
  std::shared_ptr<VertexComputation<float, float, float>>
  createComputation() const override;
  void aggregators(std::vector<std::unique_ptr<Aggregator>> &aggregators) override;
};
}
}
}
#endif
