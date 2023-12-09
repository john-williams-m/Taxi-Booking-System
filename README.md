# Documentation for Taxi Booking System:

1. **Introduction:**
   The Taxi Booking System is a simple program that simulates a reservation system for taxis. It includes the definition of three classes: `Booking`, `Taxi`, and `ReservationSystem`. Users can book taxis, view details of the available taxis, and exit the system.

2. **Class Definitions:**

   a. **Booking Class:**

   - Represents a booking made by a customer.
   - Attributes:
     - `booking_id`: Unique identifier for the booking.
     - `customer_id`: Identifier for the customer making the booking.
     - `pick_up`: Pickup point for the booking (A to E).
     - `drop`: Drop point for the booking (A to E).
     - `amount`: Amount/fare for the booking.

   b. **Taxi Class:**

   - Represents a taxi in the system.
   - Attributes:
     - `id`: Unique identifier for the taxi.
     - `earnings`: Total earnings of the taxi.
     - `current_point`: Current location of the taxi (A to E).
     - `free_time`: Next available time for the taxi.
     - `b`: Vector of Booking objects associated with the taxi.
   - Methods:
     - `Taxi(int idx)`: Constructor to initialize taxi attributes.
     - `printDetail()`: Print details of the taxi, including bookings.
     - `assignTaxi(...)`: Assign a taxi to a booking, updating taxi attributes and storing booking information.

   c. **ReservationSystem Class:**

   - Manages the overall taxi reservation system.
   - Attributes:
     - `id`: Unique identifier for bookings.
     - `taxies`: Vector of Taxi objects representing the fleet.
   - Methods:
     - `ReservationSystem(int num)`: Constructor to initialize the system with a specified number of taxis.
     - `printDetails()`: Print details of all taxis in the system.
     - `nearestTaxi(...)`: Find the nearest available taxi based on pickup point and time.
     - `bookTaxi()`: Accept user input for booking a taxi.

3. **Main Function:**

   - Initializes a `ReservationSystem` object with a fleet of taxis.
   - Enters a loop to provide a menu for users:
     - **Book:** Allows users to book a taxi.
     - **Print Details:** Displays details of all taxis in the system.
     - **Exit:** Exits the program.

4. **User Input and Validation:**

   - Users can input pickup and drop points (A to E) and pickup time.
   - Input validation ensures that only valid points are accepted.

5. **Taxi Allocation Logic:**

   - The system determines the nearest available taxi based on pickup point and time.
   - Taxi allocation considers both distance and the taxi's current earnings.

6. **Fare Calculation:**

   - The fare for each booking is calculated based on distance traveled.

7. **Sample Usage:**

   - Users can interactively book taxis and view the status of the taxi fleet.

8. **Conclusion:**
   The Taxi Booking System provides a simple simulation of taxi reservation, demonstrating the allocation of taxis based on distance, availability, and earnings. The program allows users to make bookings and view the current status of the taxi fleet.
