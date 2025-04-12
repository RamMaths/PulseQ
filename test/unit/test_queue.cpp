#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>  // Updated include
#include <pulseq/queue/queue_manager.hpp>

TEST_CASE("Basic queue operations") {
    pulseq::QueueManager q;
    
    SECTION("Enqueue and dequeue") {
        q.enqueue({"id1", "test", 30});
        auto msg = q.dequeue();
        REQUIRE(msg.id == "id1");
    }
}
