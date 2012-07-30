////////////////////////////////////////////////////////////////////////////////
/// @brief binary server
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2004-2012 triAGENS GmbH, Cologne, Germany
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
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Achim Brandt
/// @author Copyright 2009-2012, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_HTTP_SERVER_BINARY_SERVER_H
#define TRIAGENS_HTTP_SERVER_BINARY_SERVER_H 1

#include "GeneralServer/GeneralServerDispatcher.h"

#include "BinaryServer/GeneralBinaryServer.h"
#include "BinaryServer/BinaryCommTask.h"

// -----------------------------------------------------------------------------
// --SECTION--                                              forward declarations
// -----------------------------------------------------------------------------

namespace triagens {
  namespace rest {
    class HttpHandlerFactory;

// -----------------------------------------------------------------------------
// --SECTION--                                                class BinaryServer
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup HttpServer
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief binary server implementation
////////////////////////////////////////////////////////////////////////////////

    class BinaryServer : public GeneralBinaryServer<BinaryServer, HttpHandlerFactory, BinaryCommTask<BinaryServer> > {

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                      constructors and destructors
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup HttpServer
/// @{
////////////////////////////////////////////////////////////////////////////////

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief constructs a new binary server
////////////////////////////////////////////////////////////////////////////////

        BinaryServer (Scheduler* scheduler,
                    Dispatcher* dispatcher,
                    HttpHandlerFactory* handlerFactory) 
        : GeneralServer<BinaryServer, HttpHandlerFactory, BinaryCommTask<BinaryServer> >(scheduler),
          GeneralServerDispatcher<BinaryServer, HttpHandlerFactory, BinaryCommTask<BinaryServer> >(scheduler, dispatcher),
          GeneralBinaryServer<BinaryServer, HttpHandlerFactory, BinaryCommTask<BinaryServer> >(scheduler, dispatcher, handlerFactory) {
        }

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                      constructors and destructors
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup HttpServer
/// @{
////////////////////////////////////////////////////////////////////////////////

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief return encryption to be used
////////////////////////////////////////////////////////////////////////////////
          
        virtual Endpoint::Encryption getEncryption () const {
          return Endpoint::ENCRYPTION_NONE;
        }

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

    };
  }
}

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

#endif

// -----------------------------------------------------------------------------
// --SECTION--                                                       END-OF-FILE
// -----------------------------------------------------------------------------

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|// --SECTION--\\|/// @\\}\\)"
// End:
