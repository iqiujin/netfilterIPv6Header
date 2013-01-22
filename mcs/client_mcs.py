#!/usr/bin/env python

#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements. See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership. The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License. You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the
# specific language governing permissions and limitations
# under the License.
#

import sys
sys.path.append('../common')

from calcute_server import Executer
from calcute_server.ttypes import *

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol


  # Make socket
transport = TSocket.TSocket('localhost', 9090)

  # Buffering is critical. Raw sockets are very slow
transport = TTransport.TBufferedTransport(transport)

  # Wrap in a protocol
protocol = TBinaryProtocol.TBinaryProtocol(transport)

# Create a client to use the protocol encoder
client = Executer.Client(protocol)

print 'open client.'
# Connect!
transport.open()
# TODO to get commands from the web command
client.add_measure_group('ff15::1',5)
#add_measure_group()
#set_interval()

# Close!
transport.close()
print 'close client.'
