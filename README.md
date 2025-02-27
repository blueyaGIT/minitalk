<p align="center">
  <img src="https://github.com/blueyaGIT/blueyaGIT/blob/master/42_badges/minitalkm.png?raw=true" alt="minitalk"/>
</p>

<p align="center">
  Score: <i>125/100</i><br>
  Finished: <i>03.11.2024</i><br>
</p>

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

## 🚀 Next Project

<a href="https://github.com/blueyaGIT/so_long"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=BF94E4&width=435&lines=so_long"></a>

## ⏳ Previous Project

<a href="https://github.com/blueyaGIT/get_next_line"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&pause=1000&color=BF94E4&width=435&lines=get_next_line"></a>
