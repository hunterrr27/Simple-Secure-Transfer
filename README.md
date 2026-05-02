# Simple-Secure-Transfer

My attempt on building a **Stateful TCP Server**, i.e. without HTTP.

---

A typical flow looks like this:

1.  **Handshake:** Client sends a fixed-size `Header` struct.
    *   *Struct contents:* File Name (fixed char array), File Size (uint64_t), and an IV (Initialization Vector) for your encryption.
2.  **Acknowledgment:** Server sends 1 byte back (`0x01`) to say "Ready."
3.  **Data Stream:** Client reads 4KB from disk -> Encrypts it -> `send()` over socket.
4.  **Completion:** Server receives $N$ bytes (where $N = \text{File Size}$), closes the file, and sends a "Success" message.

---

**Goal:** Is to focus on **Binary Data Transfer**. Learning to pack a C++ `struct` into a buffer, send it, and unpack it on the other side.

---

### **Quick Implementation Tip**
Start by making the transfer work in **Plaintext** on your local machine (`127.0.0.1`). Once the file arrives uncorrupted, only *then* add the encryption layer. Debugging network code and encryption math at the same time is a recipe for a headache!