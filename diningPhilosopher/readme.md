# 🍝 Dining Philosophers Problem (Deadlock-Free) in C

This repository contains a C implementation of the **Dining Philosophers Problem** using POSIX threads, ensuring that **deadlock is avoided** using an **odd-even strategy**.

---

## 🧠 Problem Summary

In the **Dining Philosophers Problem**, `N` philosophers sit around a table, each needing two chopsticks (left and right) to eat. They alternate between **thinking** and **eating**.

The challenge is to:
- Avoid **deadlock** (where all philosophers hold one chopstick and wait)
- Avoid **starvation** (where some philosophers never get to eat)

---

## ✅ Strategy Used: Odd-Even Order to Avoid Deadlock

- Even-numbered philosophers pick **left then right** chopstick.
- Odd-numbered philosophers pick **right then left** chopstick.
- This breaks the circular wait condition, ensuring **deadlock is avoided**.

---
