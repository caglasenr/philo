*This project has been created as part of the 42 curriculum by csener*

## Description

The Philosophers project is a classical concurrency problem that is widely used in computer science to teach the fundamentals of multithreading, synchronization, and shared resource management.

In this scenario, several philosophers are sitting around a circular table. Between every two philosophers there is a single fork. Since the number of forks is equal to the number of philosophers, each philosopher has one fork on their left side and one fork on their right side.

A philosopher spends their time alternating between thinking, eating, and sleeping. However, in order to eat, a philosopher must hold both forks at the same time. This creates a synchronization challenge because forks are shared resources and cannot be used by more than one philosopher simultaneously.

The goal of this project is to simulate this situation using threads and ensure that philosophers behave correctly without causing problems such as race conditions and deadlocks. To achieve this, the program uses mutexes to protect shared resources and coordinate access to forks.

Through this implementation, the project demonstrates how concurrent processes interact, how synchronization mechanisms work, and how to manage shared resources safely in a multithreaded environment.

## Instructions

### **Compilation**

Compile the project using:

```bash
make
```

### **Execution**

Run the program with the following format: `./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> <must_eat_count>`

```bash
./philo 4 410 200 200
```

- `<number_of_philosophers>` → Total philosophers
- `<time_to_die>` → Time before death in milliseconds
- `<time_to_eat>` → Eating duration in milliseconds
- `<time_to_sleep>` → Sleeping duration in milliseconds
- `<must_eat_count>` → Number of times each philosopher must eat (optional)

## Resources

- https://medium.com/@ardaerdogani/thread-ve-process-6b383f20fe9
- https://www.yusufsezer.com.tr/cpp-thread/
- https://bilgisayarkavramlari.com/2012/01/22/filozoflarin-aksam-yemegi-dining-philosophers/
- https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2 

### **AI Usage**

AI (ChatGPT) was used during the project for:

- Planning a roadmap for the project
- Translating text while creating the README.md file
- Clarifying concepts and instructions