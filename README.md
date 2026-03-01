*This project has been created as part of the 42 curriculum by csener*

## Description

The Philosophers project is a classical concurrency problem used to teach fundamental concepts of multithreading, synchronization , and resource management .

In this project, philosophers sit around a circular table and wait to eat. Each philosopher has a fork on their left and right side. The total number of forks is equal to the number of philosophers. In order to eat, a philosopher must acquire both the left and right forks.

The main objective of this project is to implement threads and use mutexes to prevent race conditions and deadlocks . The project focuses on handling shared resources safely and ensuring proper synchronization between threads.

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