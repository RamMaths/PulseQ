#pragma once
#include <boost/asio.hpp>
#include <pulseq/queue/queue_manager.hpp>

namespace pulseq {

class NetworkServer {
public:
    NetworkServer(QueueManager& queue);
    void run(unsigned short port);
    
private:
    void start_accept();
    
    boost::asio::io_context io_context_;
    QueueManager& queue_;
};

} // namespace pulseq
