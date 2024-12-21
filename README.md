# Airline Safety Data Sorting Program

## Overview

This C++ program processes and sorts airline safety data from a CSV file. The dataset includes information about airlines, available seat kilometers, and incidents reported in two different time periods. The program uses Bubble Sort and Selection Sort algorithms to organize the data based on the total number of incidents and outputs the results in both the console and separate CSV files.

## Features

### Input

- Reads airline safety data from a CSV file (`airline-safety.csv`), containing:
  - Airline name
  - Available seat kilometers per week
  - Number of incidents (1985–1999)
  - Number of incidents (2000–2014)

### Sorting Algorithms

#### Bubble Sort

- Sorts airline data in ascending order based on the total number of incidents.
- Displays the sorted data in the console.
- Writes the sorted data to `DataBubbleSorted.csv`.

#### Selection Sort

- Sorts airline data in ascending order based on the total number of incidents.
- Displays the sorted data in the console.
- Writes the sorted data to `DataSelectionSorted.csv`.

### Output

- Displays the unsorted data, Bubble Sorted data, and Selection Sorted data in the console.
- Outputs sorted data to respective CSV files:
  - `DataBubbleSorted.csv`
  - `DataSelectionSorted.csv`

### Additional Features

- Shows the total number of swaps performed by each sorting algorithm.
- Provides a neatly formatted console display of the data for better readability.

## How to Run

### Clone the repository

```bash
git clone https://github.com/YourUsername/AirlineSafetyDataSorting.git
cd AirlineSafetyDataSorting
```
