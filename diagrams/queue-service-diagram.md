```mermaid
graph td
    nl[networking layer request]
    qm[queue manager]
    wp[worker thread pool]
    sl[storage layer]
    ch[consumer handler]
    vtm[visibility timeout manager]
    dlq[dead-letter queue]

    nl --> qm
    qm --> wp
    wp --> sl
    wp --> ch
    qm --> vtm
    vtm -- "requeue on timeout" --> wp
    wp -- "exceeds retry limit" --> dlq
```
