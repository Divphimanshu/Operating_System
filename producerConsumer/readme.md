# 🏭 Producer-Consumer Problem in C

This repository contains a simulation of the classic **Producer-Consumer Problem** using **POSIX threads (pthreads)** and **semaphores** in C.

---

## 🧠 Problem Statement

In the **Producer-Consumer Problem**, we have:
- A shared **bounded buffer**
- A **Producer** that inserts items into the buffer
- A **Consumer** that removes items from the buffer

Proper synchronization is required to:
- Prevent buffer overflow (Producer can't write if buffer is full)
- Prevent buffer underflow (Consumer can't read if buffer is empty)

---

## 🔧 Implementation Details

- Language: C
- Threading: `pthread.h`
- Synchronization: `semaphore.h` and `pthread_mutex_t`
- Buffer: Circular array of size 5

---

## 🚦 Synchronization Mechanism

| Component   | Purpose                        |
|-------------|--------------------------------|
| `empty`     | Semaphore to track empty slots |
| `full`      | Semaphore to track filled slots|
| `mutex`     | Mutex lock for critical section|

---

