# 📚 Reader-Writer Problem in C (Using POSIX Threads)

This repository implements the classic **Reader-Writer Problem** using **pthreads** and **semaphores** in C.

---

## 🧠 What is the Reader-Writer Problem?

It’s a classic synchronization problem used to manage access to shared data:
- **Multiple readers** can read at the same time.
- **Writers** need **exclusive access** to write.
- In the **first readers-writers problem**, **readers are given priority** over writers.

---

## 🔧 How It Works

- Readers increment a `readcount`. If it's the **first reader**, it **locks the writer** using a semaphore.
- Writers wait on a semaphore (`wrt`) to write. Only **one writer** can write at a time.
- When the **last reader finishes**, it **unlocks the writer**.

---

