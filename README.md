<div align="center">
  <img src="img/philosophers.png" alt="Logo" width="150" height="150">
  <h2>42 PHILOSOPHERS PROJECT</h2>
    <a href= https://github.com/emre-mr246/42-evaluation><img src="https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge"/></a>
    <a href= https://github.com/emre-mr246/42-evaluation><img src="https://img.shields.io/badge/circle-3-magenta?style=for-the-badge"/></a>
    <a href= https://github.com/emre-mr246/42-evaluation><img src="https://img.shields.io/badge/42-Evaluation-red?style=for-the-badge"/></a>
    <a href= https://github.com/emre-mr246/42-evaluation><img src="https://img.shields.io/github/last-commit/emre-mr246/42_ring3_philosophers?style=for-the-badge"/></a>
    <a href="https://42istanbul.com.tr/"><img src="https://img.shields.io/badge/42-ISTANBUL-white?style=for-the-badge"/></a>
   
<h4>
    <a href="https://github.com/emre-mr246/42_ring3_philosophers/issues">❔ Ask a Question</a>
  <span> · </span>
    <a href="https://github.com/emre-mr246/42_ring3_philosophers/issues">🪲 Report Bug</a>
  <span> · </span>
    <a href="https://github.com/emre-mr246/42_ring3_philosophers/issues">💬 Request Feature</a>
</h4>
</div>

## Introduction 🚀

The 42 Philosophers project is a simulation of the classic Dining Philosophers problem, which illustrates the challenges of concurrency, synchronization, and resource sharing in a multithreaded environment. The project involves a set number of philosophers who alternately think and eat, but to eat, they need access to limited resources (forks). The goal is to manage these resources and avoid deadlocks or race conditions while ensuring that no philosopher starves. This project tests skills in multithreading, mutexes and semaphores.

The project was tested with two separate testers. Additionally, race conditions were checked using various parameters, such as -fsanitize=thread, passed to the compiler.

I couldn't create the project tree because the subject requires all files to be in the philo and philo_bonus directories.

## Image 📸

![](img/screenshot.png)

## Mandatory Part(with mutexes) Usage 🔍

1.  In the philo directory, compile the library using the `make` command.
   `$ make` 
    
2.  After compilation, you can use the program as follows:
    `./philo <philo_count> <time_to_die> <time_to_eat> <time_to_sleep> <max_meal_count_per_philo>`

## Bonus Part(with semaphores) Usage 🔍
1.  In the philo_bonus directory, compile the library using the `make` command.
   `$ make` 
    
2.  After compilation, you can use the program as follows:
    `./philo_bonus <philo_count> <time_to_die> <time_to_eat> <time_to_sleep> <max_meal_count_per_philo>`
