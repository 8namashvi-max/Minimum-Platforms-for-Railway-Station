# 🚉 Minimum Platforms for Railway Station

A C++ implementation of the **Minimum Platform Problem** using a **Greedy Algorithm** and efficient data structures. The program determines the minimum number of railway platforms required so that no train has to wait, while also supporting platform prioritization for Express trains, peak usage analysis, and platform utilization statistics.

---

## 📌 Features

- Calculate minimum number of platforms required
- Assign platforms efficiently using a Greedy approach
- Priority scheduling for Express and Local trains
- Detect busiest (peak) time interval
- Identify the most frequently used platform
- Configurable buffer time between consecutive trains
- Efficient implementation using STL data structures

---

## 🧠 Algorithm Used

### Greedy Scheduling Algorithm

The algorithm follows these steps:

1. Convert train timings into minutes.
2. Add a configurable buffer time after each departure.
3. Sort trains by arrival time.
   - If arrival times are equal, Express trains are given priority.
4. Free platforms whose trains have already departed.
5. Assign an available platform or create a new one if necessary.
6. Track:
   - Maximum simultaneous platform usage
   - Peak usage interval
   - Platform usage frequency

Overall Time Complexity:

```
O(n log n)
```

---

## 📂 Data Structures Used

### Priority Queue (Min Heap)

Stores:

```
(departure_time, platform_id)
```

Purpose:
- Track occupied platforms
- Retrieve the earliest available platform efficiently

---

### Set

Stores available platform IDs.

Used to:
- Assign the smallest available platform to Express trains
- Assign the largest available platform to Local trains

---

### Vector

Stores:
- Train details
- Assigned platform numbers

---

### Map

Used to count how many times each platform is assigned.

---

## ⚙️ Input Format

```
Number of trains

Arrival_Time Departure_Time Train_Type
```

Train Type:

```
1 → Express
0 → Local
```

Example:

```
5

09:00 09:30 0
09:10 09:40 1
09:20 10:00 0
09:45 10:15 1
10:00 10:30 0
```

---

## 📤 Output

The program displays:

- Minimum platforms required
- Peak platform usage interval
- Most frequently used platform
- Platform assigned to every train

---

## ⭐ Additional Features

### Peak Time Detection

Finds the busiest time interval when the maximum number of platforms are occupied simultaneously.

### Express vs Local Priority

- Express trains receive the smallest available platform ID.
- Local trains receive the largest available platform ID.

### Platform Usage Analysis

Tracks how many times each platform is used and reports the most frequently occupied platform.

---

## 📊 Time Complexity

| Operation | Complexity |
|-----------|------------|
| Sorting Trains | O(n log n) |
| Heap Operations | O(log n) |
| Set Operations | O(log n) |
| Platform Assignment | O(n log n) |
| Overall | **O(n log n)** |

---

## 💻 Technologies Used

- C++
- STL
  - Vector
  - Priority Queue
  - Set
  - Map
- Greedy Algorithm

---

## 🎯 Applications

- Railway station scheduling
- Airport runway allocation
- CPU process scheduling
- Resource allocation systems
- Event scheduling

---

This project was developed as part of the **Design and Analysis of Algorithms (DAA)** course for educational purposes.
