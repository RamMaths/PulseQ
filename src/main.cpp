#include <pulseq/networking/server.hpp>
#include <pulseq/queue/queue_manager.hpp>

int main() {
    pulseq::QueueManager queue;
    pulseq::NetworkServer server(queue);
    server.run(8080);
    return 0;
}
