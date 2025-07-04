# 🧮 Banker's Algorithm Implementation in C

This repository contains a C program that simulates **Banker’s Algorithm** – a deadlock avoidance algorithm used in Operating Systems.

---

## 📌 What is Banker’s Algorithm?

Banker's Algorithm is used to determine whether it is safe to grant a resource request made by a process, **without leading the system into an unsafe (deadlock) state**.

It uses:
- **Allocation Matrix** – resources currently allocated
- **Maximum Matrix** – maximum resources needed by each process
- **Available Vector** – currently available resources
- **Need Matrix** – resources still needed by each process

---

## 💡 Features

✅ Accepts dynamic number of processes and resources  
✅ Calculates the **Need matrix**  
✅ Performs the **Safety check**  
✅ Outputs a **safe sequence** if the system is in a safe state  
❌ Stops if the system is in an unsafe state

---

