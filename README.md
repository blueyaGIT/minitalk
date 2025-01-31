<a href="https://github.com/blueyaGIT/minitalk"><img src="https://github.com/blueyaGIT/blueyaGIT/blob/b34a5a4e10b9019609659eaa0541a4325db88ca5/covers/cover-minitalk-bonus.png"></a>
###

`minitalk` is a project that implements inter-process communication using UNIX signals. It consists of a client and a server program, where the client sends messages to the server using `SIGUSR1` and `SIGUSR2` signals. This project is part of the 42 School curriculum.

## Usage

To use `minitalk`, clone the repository in the root of your project using one of the following commands:

#### SSH
```bash
git clone git@github.com:blueyaGIT/minitalk.git
```
#### HTTPS
```bash
git clone https://github.com/blueyaGIT/minitalk.git
```
#### GitHub CLI
```bash
gh repo clone blueyaGIT/minitalk
```
This will create a directory called `minitalk/`. Enter it with the command:

```bash
cd minitalk
```

### Compiling

To compile both the server and the client, use:

```bash
make
```

This will generate two executables:
- `server`
- `client`

## Running the Program

### Start the server
Run the server first, as it will wait for incoming messages:

```bash
./server
```
The server will print its **Process ID (PID)**, which is required for the client to send messages.

### Send a message from the client
Use the client to send a message to the server using its PID:

```bash
./client <server_pid> "Your message here"
```
For example:

```bash
./client 12345 "Hello, World!"
```

## Files

- `server.c` - Implements the server logic, receiving and processing signals.
- `client.c` - Implements the client logic, converting messages into signals.
- `minitalk.h` - Header file containing function prototypes and necessary includes.
- `Makefile` - Automates the compilation of the project.

## Signal Handling

- `SIGUSR1` - Represents a binary `0`.
- `SIGUSR2` - Represents a binary `1`.

The client converts each character of the message into binary and sends it bit by bit using these signals. The server reconstructs the message and prints it.

## Bonus

The bonus version includes additional features such as:
- Handling Unicode characters.
- Acknowledgement signals from the server to confirm receipt of each character.

To compile with bonus support, use:

```bash
make bonus
```

## Notes

- The server must be running before sending messages.
- Ensure that the PID provided to the client is correct.
- The implementation uses `usleep()` to manage signal timing and avoid data loss.

For more details, refer to the project documentation or the `42` subject PDF.