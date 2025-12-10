# Minitalk

**Minitalk** is a small client-server communication program that uses UNIX signals to exchange data between processes.

## Description

The project consists of a server and a client. Communication between the client and the server is achieved using only two UNIX signals: `SIGUSR1` and `SIGUSR2`.
- `SIGUSR1` represents a `0` bit.
- `SIGUSR2` represents a `1` bit.

The client converts the message string into binary and sends it bit by bit to the server. The server reconstructs the message and prints it. The server also sends acknowledgements back to the client after each bit is received.

## Features

- **Signal-based Communication:** Uses `SIGUSR1` and `SIGUSR2` for all data transfer.
- **Bit-by-Bit Transmission:** Characters are decomposed into bits and transmitted sequentially.
- **Acknowledgements:** The server acknowledges every bit received, ensuring synchronization.
- **Busy Signal:** If the server is receiving a message from another client, it sends a signal back to other potential senders indicating it is busy.

## Compilation

To compile the project, run `make` in the terminal:

```bash
make
```

This will generate two executables: `server` and `client`.

To compile the bonus version (functionally equivalent in this implementation):

```bash
make bonus
```

This will generate `server_bonus` and `client_bonus`.

Other Make commands:
- `make clean`: Removes object files.
- `make fclean`: Removes object files and executables.
- `make re`: Recompiles the project from scratch.

## Usage

### 1. Start the Server

Run the server first. It will print its Process ID (PID).

```bash
./server
```

Output example:
```
The PID of the server: 12345
```

### 2. Run the Client

In a separate terminal, run the client with the server's PID and the message you want to send.

```bash
./client [PID] "Your message here"
```

Example:
```bash
./client 12345 "Hello, World!"
```

### Server Output
The server will print the received message once the transmission is complete.

```
Hello, World!
```

### Client Output
The client will confirm when the message has been successfully sent.

```
Message sent
```

## Dependencies

- **Libft:** A custom C library used for various utility functions (included in the `libft/` directory).
