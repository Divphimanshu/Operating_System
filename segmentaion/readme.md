# 🧠 Segmentation Simulation in C

This repository contains a simple C program that simulates **memory segmentation**, one of the memory management techniques used by operating systems.

## 💡 Description

In this simulation:
- Each process is divided into segments like Code, Data, Stack, etc.
- Each segment has a name, base address, and limit (size).
- The user can provide segment details and convert logical addresses to physical addresses using the segment table.

## 📂 Features

- Input multiple segments with base and limit values.
- Convert logical address (segment + offset) to physical address.
- Validate if the offset is within segment limits.
- Error messages for invalid segments or out-of-bound offsets.

