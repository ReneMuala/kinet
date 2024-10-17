#include "track.h"

void track::handleNewMessage(const WebSocketConnectionPtr& wsConnPtr, std::string &&message, const WebSocketMessageType &type)
{
    // write your application logic here
    auto engine = engines[wsConnPtr->peerAddr().toIp()];
    if(message.starts_with("%STAT"))
    {
        std::string response;
        for(const auto & entt : engine->entities)
        {
            response += entt->id + " " + entt->name + " | ";
            for(auto & lm : entt->limbos)
            {
                response += lm.first + " " + std::to_string(lm.second.count());
            }
            response += "\n";
        }
    } else if(message.length() > 10)
    {
        wsConnPtr->send(std::to_string(engine->step(message)));
    }
}

void track::handleNewConnection(const HttpRequestPtr &req, const WebSocketConnectionPtr& wsConnPtr)
{
    // write your application logic here
    wsConnPtr->send("Welcome to Kinet");
    engines[wsConnPtr->peerAddr().toIp()] = std::make_shared<service::Engine>();
}

void track::handleConnectionClosed(const WebSocketConnectionPtr& wsConnPtr)
{
    // write your application logic here
    engines[wsConnPtr->peerAddr().toIp()] = nullptr;
}
