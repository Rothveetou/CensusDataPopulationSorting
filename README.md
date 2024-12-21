# CensusDataPopulationSorting

## US Census Population Data Sorting Program

This repository contains a C++ program designed to read, process, and sort US Census population data for states and territories. The program implements two sorting algorithms—Bubble Sort and Selection Sort—to organize the data based on specific fields, including total population. The results are displayed in the console and written to separate output files.

---

## Features

- **Data Input**: Reads data from a CSV file (`CensusData.csv`) containing the following fields:
  - State or territory name
  - Total population
  - Adult population
  - Percentage of adults in the population

- **Sorting Algorithms**:
  - **Bubble Sort**: Implements an iterative approach for sorting and displays the sorted data in descending order by total population.
  - **Selection Sort**: Implements a comparison-based sorting method and displays the sorted data in descending order by total population.

- **Output**: Generates two CSV files, `DataBubbleSorted.csv` and `DataSelectionSorted.csv`, containing the sorted data.

### Additional Features
- Option to use a custom input file for extra credit, requiring detailed comments at the top of the source code describing:
  - The file structure
  - The sort field
  - Whether the sorting is in ascending or descending order
- Displays detailed information about the number of swaps made by each sorting algorithm.

---

## How to Run

1. **Clone the repository**:
   ```bash
   git clone https://github.com/YourUsername/CensusDataPopulationSorting.git
2. Compile the program
   ```bash
   g++ -o CensusSorter <YourFirstName><YourLastName>_CS22_Program4.cpp
3. Place the Census.csv file (inputFile) in the same directory
    - Display the unsorted data.
    - Sort the data using Bubble Sort and Selection Sort.
    - Display the sorted data.
    - Generate output files for each sorting algorithm.

## Author
Rothvitou Meng
