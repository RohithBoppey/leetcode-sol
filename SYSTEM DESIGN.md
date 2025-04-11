Reference: https://www.youtube.com/playlist?app=desktop&list=PL6W8uoQQ2c61X_9e6Net0WdYZidm7zooW

Topics: OOPS, SOLID Principles, Design Patterns
![image](https://github.com/user-attachments/assets/63ca05de-dd93-4b95-8883-9d39c4a48757)

![image](https://github.com/user-attachments/assets/aa893d8e-ff49-4356-a32d-03fc9f11b067)

## Solid Principles

These are used to create reliable and maintainable and scalable software code. 

| Single responsibility Principle | Any function or class should only be responsible for a single function                                                                            |
|---------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|
| Open Closed Principle           | Code should be open for extension, but not for modification (Shapes - Circle, Rectangle \| Area example)                                          |
| Liskov Substitution Principle   | Use inheritance only when subclass can replace the parent class ; Use more abstraction to prevent errors                                          |
| Interface Segregation Principle | User should only use the interfaces he want to (Vehicle - Car, Boat)                                                                              |
| Dependency Inversion Principle  | Higher level modules should not depend on lower level modules implementation (Orders, Payment Gateway - can change this without modifying others) |

1. Single Responsibility - Every single thing - class, method, function should only serve a single puprpose. Separation of concerns -> increase modularity.
```python
class Invoice:
    def __init__(self, items):
        self.items = items

    def calculate_total(self):
        return sum(item['price'] * item['quantity'] for item in self.items)

class InvoicePrinter:
    def print_invoice(self, invoice):
        print("Invoice Total:", invoice.calculate_total())

class InvoiceSaver:
    def save_to_db(self, invoice):
        print("Saving invoice to DB...")

# SRP: Each class has a single responsibility: calculating, printing, saving.

```
2. Open and Closed Principle - Any new functionality should be added without changing the existing code - like components should be added or removed accordingly. Exact point: "Code should be open for extension but closed for modification."
```py
from abc import ABC, abstractmethod

class DiscountStrategy(ABC):
    @abstractmethod
    def apply_discount(self, total):
        pass

class NoDiscount(DiscountStrategy):
    def apply_discount(self, total):
        return total

class BlackFridayDiscount(DiscountStrategy):
    def apply_discount(self, total):
        return total * 0.7

class Checkout:
    def __init__(self, discount_strategy: DiscountStrategy):
        self.discount_strategy = discount_strategy

    def calculate_total(self, total):
        return self.discount_strategy.apply_discount(total)

# Adding a new discount doesn't touch Checkout or existing classes—just add another strategy. I can simply add a new discount stategy without modifying the checkout

```

3. Liskov Substitution Principle - Should allow to use interfaces as a "IS A" relationship. This helps to scale the application up. "Subtypes must be substitutable for their base types without breaking the program." - "If your app works with a parent class, it should also work with a child class—without crashing or misbehaving." Liskov says: Don’t use inheritance if the subclass can’t truly “act like” the parent.

```py
class Bird:
    def fly(self):
        print("Flying...")

class Sparrow(Bird):
    pass

class Ostrich(Bird):
    def fly(self):
        raise NotImplementedError("Ostriches can't fly!")

# Violation! Ostrich is not substitutable.

# Fix:
class Bird(ABC):
    @abstractmethod
    def move(self):
        pass

class FlyingBird(Bird):
    def move(self):
        print("Flying...")

class WalkingBird(Bird):
    def move(self):
        print("Walking...")

# Now FlyingBird and WalkingBird are substitutable and respected.

```

```py
# Imagine a vehicle rental application in which you are renting the application

# ------------------------------------- APPROACH 1 --------------------------------------

class Vehicle:
    def start_engine(self):
        print("Engine started")

class Car(Vehicle):
    def start_engine(self):
        print("Car engine started")

class Bike(Vehicle):
    def start_engine(self):
        print("Bike engine started")

def prepare_trip(vehicle: Vehicle):
    vehicle.start_engine() # ✅ this works

# now this is getting added
class Bicycle(Vehicle):
    def start_engine(self):
        raise Exception("Bicycles don't have engines!")

prepare_trip(Bicycle())  # ❌ Boom! Not a real substitute.

# ------------------------------------- APPROACH 2 --------------------------------------
# This approach is an even generalised one which involves engine abstraction and non engine abstraction

class Vehicle:
    pass

class EngineVehicle(Vehicle):
    def start_engine(self):
        pass

class NonEngineVehicle(Vehicle):
    def pedal(self):
        pass

class Car(EngineVehicle):
    def start_engine(self):
        print("Car engine started")

class Bike(EngineVehicle):
    def start_engine(self):
        print("Bike engine started")

class Bicycle(NonEngineVehicle):
    def pedal(self):
        print("Pedaling the bicycle")

def prepare_engine_trip(vehicle: EngineVehicle):
    vehicle.start_engine()

def prepare_manual_trip(vehicle: NonEngineVehicle):
    vehicle.pedal()

```

4. Interface segregration Principle - The art of maintaining completely independant interfaces to reduce dependancy - reduce coupling and make it completely modular. "Clients should not be forced to depend on interfaces they do not use." Use only the ones you want using inhertiance
```py
class Printer(ABC):
    @abstractmethod
    def print(self): pass

class Scanner(ABC):
    @abstractmethod
    def scan(self): pass

class MultiFunctionPrinter(Printer, Scanner):
    def print(self):
        print("Printing...")
    def scan(self):
        print("Scanning...")

class SimplePrinter(Printer):
    def print(self):
        print("Just printing...")

# Clients can choose only what they need.

```

5. Dependancy Inversion Principle - Adding Abstraction to our code - high level modules should not impact our low level modules unless we want it to. "High-level modules should not depend on low-level modules. Both should depend on abstractions."
```py
class NotificationService(ABC):
    @abstractmethod
    def send(self, message): pass

class EmailService(NotificationService):
    def send(self, message):
        print(f"Sending email: {message}")

class SMSService(NotificationService):
    def send(self, message):
        print(f"Sending SMS: {message}")

class AlertManager:
    def __init__(self, notifier: NotificationService):
        self.notifier = notifier

    def alert(self, message):
        self.notifier.send(message)

# High-level (AlertManager) depends on abstraction, not Email/SMS directly.
```
High level module - AlertManger, it does not depend on the low level implementation of Email or SMS -> instead it depends on the abstraction of low level module (NotificationService) 
