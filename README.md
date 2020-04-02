# Vending-Machine
Complete Backend Design of a Beverage Vending Machine written in C++

* The design of the Beverage Vending Machine is as follows:
* It consists of Beverage base class at the top which contains all the common parameters shared 
  between 5 Beverage Types namely:
                    * Soda based
                    * Coffee based
                    * Tea based
                    * Fruit based
                    * Milk based
* All sub-classes are derived from the Beverage Base class.

* Used the following Design Pattern and concepts:
                    * Singleton pattern
                    * Inheritance/ Polymorphism
                    * CRUD operations.
* The application serves in 2 modes namely
                    * Maintainance mode (perform CRUD)
                    * Consumer Mode (Buy Items, add Credit etc.)
* List of functions available for Maintainance Mode:
                    * Create
                    * Update
                    * Delete
                    * Reset
                    * Get All
                    * Get By ID
                    * Delete All
                    * Delete By ID
* List of functions available for Consumer Mode:
                    * View Items
                    * Buy Items
                    * Recharge Credit
                    * View Details
* Things to improve
      * Use of generics to create modular code.
      * Better validation and algoritms for search.
* RUN INSTRUCTIONS:
                   * Go to Debug/ folder.
                   * Run Vending Machine.exe
