/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "./gen-cpp/RecvMessage.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace tutorial;
using namespace shared;

using namespace boost;


int sendmsg(const std::string& msg) {

    
  shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  shared_ptr<TTransport> transport(new TFramedTransport(socket));
  shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  RecvMessageClient client(protocol);

  try {
    transport->open();

    client.send_measure_info(msg);

    transport->close();
  } catch (TException &tx) {
    printf("ERROR: %s\n", tx.what());
  }

}