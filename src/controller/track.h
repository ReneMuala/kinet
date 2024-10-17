#pragma once

#include <drogon/WebSocketController.h>
#include <unordered_map>

#include "../service/Engine.h"
using namespace drogon;

class track : public drogon::WebSocketController<track>
{
    std::unordered_map<std::string, std::shared_ptr<service::Engine>> engines;
  public:
     void handleNewMessage(const WebSocketConnectionPtr&,
                                  std::string &&,
                                  const WebSocketMessageType &) override;
    void handleNewConnection(const HttpRequestPtr &,
                                     const WebSocketConnectionPtr&) override;
    void handleConnectionClosed(const WebSocketConnectionPtr&) override;
    WS_PATH_LIST_BEGIN
    WS_PATH_ADD("/track/");
    WS_PATH_LIST_END
};
