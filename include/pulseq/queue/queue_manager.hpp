#pragma once
#include <mutex>
#include <queue>
#include <string>

namespace pulseq {

struct Message {
    std::string id;
    std::string body;
    int visibility_timeout;
};

class QueueManager {
public:
    void enqueue(const Message& msg);
    Message dequeue();
    void ack(const std::string& msg_id);
    
private:
    std::queue<Message> queue_;
    std::mutex mutex_;
};

} // namespace pulseq
