```mermaid
graph TD
    A[Incoming Requests (HTTP/WebSocket)] --> B[Async I/O Manager / Event Loop]
    B --> C[Request Dispatcher]
    C -- "POST /enqueue" --> D[Enqueue Handler]
    C -- "GET /dequeue"  --> E[Dequeue Handler]
    C -- "POST /ack"     --> F[ACK Handler]
    %% Optional monitoring/logging component
    B --> G[Logging & Monitoring]
```
