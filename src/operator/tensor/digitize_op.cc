/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*!
* Copyright (c) 2018 by Contributors
* \file digitize_op.cc
* \brief
* \author Contributors
*/

#include "./digitize_op.h"

namespace mxnet {
namespace op {

        DMLC_REGISTER_PARAMETER(DigitizeParam);

NNVM_REGISTER_OP(digitize)
.describe(R"code(Full operator description:
.. math::

    ...

)code" ADD_FILELINE)
.set_attr_parser(ParamParser<DigitizeParam>)
.set_num_inputs(1)
.set_num_outputs(1)
.set_attr<nnvm::FListInputNames>("FListInputNames",
[](const NodeAttrs& attrs) {
return std::vector<std::string>{"data"};
})
.set_attr<nnvm::FInferShape>("FInferShape", DigitizeOpShape)
.set_attr<nnvm::FInferType>("FInferType", DigitizeOpType)
.set_attr<FCompute>("FCompute", DigitizeOpForward<cpu>)
.set_attr<nnvm::FInplaceOption>("FInplaceOption",
[](const NodeAttrs& attrs) {
return std::vector<std::pair<int, int> >{{0, 0}};
})
.add_argument("data", "NDArray-or-Symbol", "Input ndarray")
.add_arguments(DigitizeParam::__FIELDS__());

}  // namespace op
}  // namespace mxnet
