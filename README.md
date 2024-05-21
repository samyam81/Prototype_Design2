# Prototype_Design2

This repository contains implementations of the Prototype design pattern in various programming languages (C++, Java, and C#). The Prototype design pattern allows you to create new objects by copying an existing object, known as a prototype.

## C++ Implementation

### LaptopShop Class
- Represents a shop that sells laptops.
- Attributes:
  - `laptopShop`: Name of the laptop shop.
  - `laptops`: Vector of shared pointers to `Laptop` objects.
  - `rd`, `gen`, `dis`: Random number generation utilities.
- Methods:
  - `getLaptopShop()`: Get the name of the laptop shop.
  - `setLaptopShop()`: Set the name of the laptop shop.
  - `getLaptops()`: Get the vector of laptops.
  - `loadData()`: Populate the shop with laptop data.
  - `operator<<()`: Overloaded stream insertion operator to print the shop details.
  - `clone()`: Create a deep copy of the laptop shop.

### Laptop Class
- Represents a laptop.
- Attributes:
  - `Lap_ID`: ID of the laptop.
  - `Lap_processor`: Processor type of the laptop.
- Methods:
  - `getLap_ID()`, `setLap_ID()`: Get and set the ID of the laptop.
  - `getLap_processor()`, `setLap_processor()`: Get and set the processor type of the laptop.

### Main Function
- Creates a `LaptopShop` object, loads data, and prints the shop details.
- Clones the shop, modifies the original shop, and prints both shops to demonstrate prototype pattern.

## Java Implementation

### LaptopShop Class
- Represents a shop that sells laptops.
- Attributes and methods are similar to the C++ implementation.

### Laptop Class
- Represents a laptop.
- Attributes and methods are similar to the C++ implementation.

### Main Method
- Similar to the C++ implementation, but uses Java syntax.

## C# Implementation

### LaptopShop Class
- Represents a shop that sells laptops.
- Attributes and methods are similar to the C++ and Java implementations.

### Laptop Class
- Represents a laptop.
- Attributes and methods are similar to the C++ and Java implementations.

### Main Method
- Similar to the C++ and Java implementations, but uses C# syntax.

## How to Use
- Compile and run the code for your desired language (C++, Java, or C#).
- View the console output to see the details of the laptop shops and their laptops.

Enjoy exploring the Prototype design pattern with Prototype_Design2!
