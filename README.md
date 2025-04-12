# 🚀 PulseQ

A blazing-fast, open-source, SQS-like message queuing system built with modern C++. Designed for quick deployment, minimal configuration, and optimized performance. Inspired by AWS SQS — without the cloud lock-in.

## ✨ Features (Planned)

- 🧠 **SQS-like Messaging Semantics** (FIFO, visibility timeout, retries, DLQ)
- ⚡ **Asynchronous Networking** (via Boost.Asio)
- 🔁 **Multithreaded Worker Pool** for concurrent processing
- 🧵 **In-Memory + Redis Hybrid Storage** (low latency + persistence)
- 📡 **Event-Driven Consumer Notification System**
- ☠️ **Dead-Letter Queue Support**
- 📦 **Easy Deployment** — no cloud, no frills, no lock-in
- 📊 **Monitoring & Logging Friendly**

---

## 📚 Architecture Overview

This project is structured into the following core services:

- **Networking Layer** (Async HTTP/WebSocket server)
- **Queue Manager** (Multithreaded message routing & orchestration)
- **Storage Layer** (In-Memory cache with Redis fallback & persistence)
- **Consumer Handler** (Handles ACKs, message delivery & subscriptions)
- **Dead-Letter Queue** (Retries, visibility timeout, failed message handling)

➡️ See [architecture.md](./docs/architecture.md) for full system diagrams and explanation.

---

## 🛠️ Getting Started

> 🔧 The project is currently in the design phase — core architecture diagrams are available, and implementation is starting soon.  

**To get involved:**

```bash
git clone https://github.com/RamMaths/PulseQ.git
cd PulseQ
```

## How to contribute

Feel free to contribute to this project. See available issues and make a pull request following our [branch naming guide](./docs/branch-naming-guide.md).

